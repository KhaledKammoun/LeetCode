class Solution {
public:
    int maximum69Number (int num) {
        string s ;
        stringstream ss;
        ss<<num ;
        ss>>s ;
        int l=s.length() ,i=0 ;
        while(s[i]!='6' && i<(l-1))
            i++ ;
        s[i]='9' ;
        return stoi(s) ;
    }
};