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
    bool search_(TrieNode* curr, string word,int index){
        if (index == word.size())
            return curr->isEnd ;
        char c = word[index] ;
        if (c =='.'){
            // check all cases .
            for (int i = 0 ;i<26 ; i++){
                if (curr->children[i] && search_(curr->children[i], word,index+1))
                    return true ;
            }
            // none of 26's cases have a value .
            return false ;
        }
        else{
            if (!curr->children[c-'a'])
                return false ;
            return search_(curr->children[c-'a'], word,index+1) ;
        }
    }
    bool search(string word) {
        return search_(root, word, 0) ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */