class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string &word, int n, int m, int i, int j, int start) {
        if (start == word.size()) {
            return true;
        }
        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == ' ' || board[i][j] != word[start]) {
            return false;
        }
        
        char temp = board[i][j] ;
        board[i][j] = ' ' ;
        if (backtracking(board, word, n, m, i + 1, j, start + 1) ||
            backtracking(board, word, n, m, i - 1, j, start + 1) ||
            backtracking(board, word, n, m, i, j + 1, start + 1) ||
            backtracking(board, word, n, m, i, j - 1, start + 1)) {
            
            return true;
        }
        
        board[i][j] = temp ;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size() ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && backtracking(board, word,n,m, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
