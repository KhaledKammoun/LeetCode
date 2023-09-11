class Trie { 
public:
    struct Trie{
        string val ;
        Trie* left ;
        Trie* right ;
        Trie() : val(""), left(nullptr), right(nullptr) ;
        Trie(string val) : val(val), left(nullptr), right(nullptr) ;
    }
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* var = root;
        TrieNode* prev = root;
        char c = ' '; // c = 'l' or 'r' : left or right ;
        for (int i = 0; var != nullptr && i < word.size(); i++) {
            prev = var;
            if (var->val[i] > word[i] || ((i == (word.size() - 1)) && var->val[i] == word[i])) {
                var = var->left;
                c = 'l';
                i = 0;
            } else if (var->val[i] < word[i] || var->val.size() < word.size()) {
                var = var->right;
                c = 'r';
                i = 0 ;
            } else {
                c = 'l';
            }
        }
        TrieNode* node = new TrieNode(word);
        if (!prev) {
            root = node;
        } else if (c == 'l') {
            prev->left = node;
        } else {
            prev->right = node;
        }
        if (root->val =="" && (root->left || root->right))
            root = ((!root->left) ? root->right : root->left) ;
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */