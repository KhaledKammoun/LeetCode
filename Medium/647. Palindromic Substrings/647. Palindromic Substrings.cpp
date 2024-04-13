class Solution {
public:
    int increaseAroundCenter(string &s, int left, int right) {
        int nbPalindrom = 0 ;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left-- ;
            right++ ;
            nbPalindrom++ ;
        }
        return nbPalindrom ;
        
    }
    int countSubstrings(string s) {
        int n = s.size() ;
        int nbPalindrom = 0 ;
        for (int i = 0; i < n; i++) {
            nbPalindrom+=increaseAroundCenter(s, i, i) ;
            nbPalindrom+=increaseAroundCenter(s, i, i+1) ;
        }
        return nbPalindrom ;
    }
};