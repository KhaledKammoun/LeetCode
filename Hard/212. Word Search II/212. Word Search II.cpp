class TrieNode {
public:
    TrieNode* left;
    TrieNode* right;
    TrieNode* prevLeft;
    TrieNode* prevRight;
    char val ;

    TrieNode(char val) : val(val) {
        left = right = prevLeft = prevRight = nullptr;
    }
};
class Solution {
public:
    unordered_map<char, vector<TrieNode*>> children;
     TrieNode* nodes[13][13];
    //Create trie nodes using DFS .
    //Search words or inverse words .
    // we'll work on children map
    void create_nodes(vector<vector<char>>& board){
       
         int n = board.size(), m = board[0].size() ;
        // Initialize the array to nullptr
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < m; j++) {
                nodes[i][j] = new TrieNode(board[i][j]);
            }
        }
       
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                TrieNode* root = nodes[i][j] ;
                if (j > 0){
                    root->prevLeft = nodes[i][j-1] ;
                    if (nodes[i][j-1])
                        nodes[i][j-1]->right = root ;
                }
                if (i > 0){
                    root->prevRight = nodes[i-1][j] ;
                    if (nodes[i-1][j])
                        nodes[i-1][j]->left = root ;
                }
                if (i < n-1){
                    root->left = nodes[i+1][j] ;
                    if (nodes[i+1][j])
                        nodes[i+1][j]->prevRight = root ;
                }
                if (j < m-1){
                    root->right = nodes[i][j+1] ;
                    if (nodes[i][j+1])
                        nodes[i][j+1]->prevLeft = root ;
                }
                
                children[board[i][j]].push_back(root) ;
                
            }
        }
    }
    bool dfs(TrieNode* root, string& word, int index) {
        if (index == word.size())
            return true;
    
        if (root && word[index] == root->val) {
            char original = root->val; // Store the original character
            root->val = '\0'; // Mark the node as visited
    
            bool found = false;
            if (root->left)
                found |= dfs(root->left, word, index + 1);
            if (root->right)
                found |= dfs(root->right, word, index + 1);
            if (root->prevLeft)
                found |= dfs(root->prevLeft, word, index + 1);
            if (root->prevRight)
                found |= dfs(root->prevRight, word, index + 1);
            root->val = original; // Restore the original character
    
            return found;
        }
    
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        create_nodes(board) ;
        vector<string> v ;
        for (auto word : words){
            for (int i = 0 ; i<children[word[0]].size() ; i++){
                if (dfs(children[word[0]][i],word,0)){
                    v.push_back(word) ;
                    break ;
                }
            }
        }
        return v ;
    }
};