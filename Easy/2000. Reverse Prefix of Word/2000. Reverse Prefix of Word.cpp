class Solution {
public:
    string reversePrefix(string word, char ch) {
        int l = word.length(),i=0 ,ind=0;
        while (i<l ){
            
            if (word[i]==ch){
                ind=i ;
                break ;
            }
            i++ ;

        }
        if (ind!=0)
            reverse(word.begin(),word.begin()+ind+1) ;
        return word ;
    }
};