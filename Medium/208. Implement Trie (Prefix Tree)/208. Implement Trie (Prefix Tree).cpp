class Trie { 
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
        
        TrieNode() {
            isEnd = false;
            memset(children, 0, sizeof(children));
        }
    };
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
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
    bool search(string word) {
        TrieNode* curr = root ;
        for (auto c : word){
            if (!curr->children[c-'a']){
                return false ;
            }
            curr = curr->children[c-'a'] ;
        }
        return curr->isEnd ;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root ;
        for (auto c : prefix){
            if (!curr->children[c-'a']){
                return false ;
            }
            curr = curr->children[c-'a'] ;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */