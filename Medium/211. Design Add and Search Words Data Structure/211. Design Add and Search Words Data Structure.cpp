class WordDictionary {
public:
    struct TrieNode{
        TrieNode* children[26] ;
        bool isEnd  ;
        TrieNode(){
            memset(children,0,sizeof(children)) ;
            isEnd = false ;
        }
    };
    TrieNode* root;
    WordDictionary(){
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root ;
        for (auto c : word){
            if (!curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode() ;
                
            }
            curr = curr->children[c-'a'] ;
            
            
        }
        curr->isEnd = true ;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */