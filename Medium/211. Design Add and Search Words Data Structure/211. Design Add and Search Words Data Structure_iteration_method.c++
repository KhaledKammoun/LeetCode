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
    bool search(string word) {
        vector<TrieNode*> v {root} ;
        for (auto c:word){
            if (c=='.'){
                int size =v.size() ;
                for (int x = 0 ; x<size ; x++){
                    for (int i = 0 ; i<26 ; i++){
                        if (v[0]->children[i])
                            v.push_back(v[0]->children[i]) ;
                    }
                    v.erase(v.begin()) ;
                }
            }
            else{
                int size =v.size() ;
                for (int x = 0 ; x<size ; x++){
                    if (v[0]->children[c-'a'])
                        v.push_back(v[0]->children[c-'a']) ;
                    
                    v.erase(v.begin()) ;
                }
            }
        }
        for (auto c:v){
            if (c->isEnd)
                return true ;
        }
        return false ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */