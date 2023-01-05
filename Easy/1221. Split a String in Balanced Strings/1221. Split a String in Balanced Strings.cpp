class Solution {
public:
    int balancedStringSplit(string s) {
        int som = 0 , l=0,r=0 ,len= s.length();
        for (int i = 0 ;i< len ; i++){
            if (s[i]=='R')
                r++ ;
            else 
                l++ ;
            if (l==r){
                som++ ;
                l=r=0 ;
            }
        }
        return som ;
    }
};