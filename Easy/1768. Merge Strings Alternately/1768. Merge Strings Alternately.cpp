class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "" ;
        int l1=word1.size() , l2=word2.size() , i=0,j=0 ;
        while (i<l1 || j <l2){
            if (i<l1)
                s.append(1,word1[i]) ;
            if (j<l2)
                s.append(1,word2[j]) ;
            i++ ;
            j++ ;
        }
        return s ;
    }
};