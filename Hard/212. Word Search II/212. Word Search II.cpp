namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            // Combine the hashes of the two integers
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}
class TrieNode {
public:
    TrieNode* left;
    TrieNode* right;
    TrieNode* prevLeft;
    TrieNode* prevRight;
    char val ;
    bool visited;

    TrieNode(char val) : val(val), visited(false) {
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
        // Initialize the array to nullptr
        for (int i = 0; i < 13;i++) {
            for (int j = 0; j < 13; j++) {
                nodes[i][j] = nullptr;
            }
        }
        int n = board.size(), m = board[0].size() ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                TrieNode* root = new TrieNode(board[i][j]) ;
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
                nodes[i][j] = root ;
                children[board[i][j]].push_back(root) ;
                
            }
        }
        // delete nodes
        // for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        //     delete it->second; // Delete the TrieNode object
        // }
        // nodes.clear();
    }
    bool dfs(TrieNode* root, string word, int index){
        if (index == word.size())
            return true ;
        else if (!root->visited && word[index]==root->val){
            root->visited = true;
            bool found = dfs(root->left, word, index) || dfs(root->right, word,index) || dfs(root->prevLeft, word, index) || dfs(root->prevRight, word, index);
            root->visited = false;  // Backtrack: unmark the node
            return found;
        }
        else 
            return false ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        create_nodes(board) ;
        vector<string> v ;
        for (auto word : words){
            for (int i = 0 ; i<children[word[0]].size() ; i++){
                if (dfs(children[word[0]][i],word,1)){
                    v.push_back(word) ;
                    break ;
                }
            }
        }
        return v ;
    }
};