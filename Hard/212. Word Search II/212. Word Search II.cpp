class TrieNode {
public:
    TrieNode* children[26] ;
    bool isEnd ;
    TrieNode() {
        memset(children, 0, sizeof(children));
        isEnd = false ;
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(string word) {
        TrieNode* curr = root ;
        for (auto c : word){
            if (!curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode() ;
            }
            curr = curr->children[c-'a'] ;
        }
        curr->isEnd = true ;
    }

    vector<string> v ;
    bool dfs(vector<vector<char>> &board, TrieNode* root, int i, int j, string word) {
        if (i>=board.size() || i<0 || j>=board[0].size() || j<0)
            return false ;
        char letter = board[i][j];
        if (letter == '#' || !root->children[letter - 'a']) {
            return false;
        }
        
        root = root->children[letter - 'a'];
        word += letter;
        
        if (root->isEnd) {
            v.push_back(word);
            root->isEnd = false; // Mark the word as found to avoid duplicates
        }
        
        char original = board[i][j]; // Save the original character
        board[i][j] = '#'; // Mark the cell as visited
        
        bool found = dfs(board, root, i - 1, j, word) || dfs(board,root, i + 1, j, word) ||
                    dfs(board, root, i, j - 1, word) || dfs(board,root, i, j + 1, word);
        
        board[i][j] = original; // Restore the original character
        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //insert words into the Trie
        for (auto c : words){
            insert(c) ;
        }
        for (int i = 0 ; i<board.size() ; i++){
            for (int j = 0 ; j<board[0].size() ; j++)
                dfs(board,root,i,j,"") ;
        }
        
        return v ;
    }
};