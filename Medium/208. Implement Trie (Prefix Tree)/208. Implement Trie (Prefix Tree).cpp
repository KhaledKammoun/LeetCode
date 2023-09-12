class Trie { 
public:
    struct TrieNode{
        string val ;
        TrieNode* left ;
        TrieNode* right ;
        TrieNode() : val(""), left(nullptr), right(nullptr) {}
        TrieNode(string val) : val(val), left(nullptr), right(nullptr) {}
    };
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
                i = -1;
            } else if (var->val[i] < word[i] || var->val.size() < word.size()) {
                var = var->right;
                c = 'r';
                i = -1;
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

    int compare(string a, string b){
        int a_len = a.size(), b_len = b.size() ;
        for (int i = 0 ;i<min(a.size(),b.size()) ; i++){
            if (a[i] > b[i])
                return 0 ; // a > b
            else if (a[i] < b[i])
                return 1 ;
        }
        //length comparing
        if (a_len > b_len)
            return 0 ; // a > b
        else if (a_len <  b_len)
            return 1 ; // a < b
        return 2 ; // a == b
    }
    bool search_(TrieNode* root, string word){
        if (!root)
            return false ;
        int x = compare(root->val, word) ;
        if (x == 1) // root->val < word ;
            return search_(root->right, word) ;
        else if (x == 0) // root->val > word
            return search_(root->left, word) ;
        else
            return true ;
    }
    bool search(string word) {
        return search_(root, word) ;
    }
    bool startsWith_(TrieNode* root, string prefix){
        if (!root)
            return false ;
        int x = compare(((root->val.size()> prefix.size()) ? root->val.substr(0,prefix.size()) : root->val),prefix) ;
        if (x == 1) // root->val < prefix ;
            return startsWith_(root->right, prefix) ;
        else if (x == 0) // root->val > prefix
            return startsWith_(root->left, prefix) ;
        else
            return true ;
    }
    bool startsWith(string prefix) {
        return startsWith_(root, prefix) ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */