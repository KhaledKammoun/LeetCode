class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string word, int n, int m, int i, int j, int start, vector<vector<bool>>& visited) {
        if (start == word.size()) {
            return true;
        }
        
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[start]) {
            return false;
        }
        
        visited[i][j] = true;
        
        if (backtracking(board, word, n, m, i + 1, j, start + 1, visited) ||
            backtracking(board, word, n, m, i - 1, j, start + 1, visited) ||
            backtracking(board, word, n, m, i, j + 1, start + 1, visited) ||
            backtracking(board, word, n, m, i, j - 1, start + 1, visited)) {
            
            return true;
        }
        
        visited[i][j] = false;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtracking(board, word, n, m, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
