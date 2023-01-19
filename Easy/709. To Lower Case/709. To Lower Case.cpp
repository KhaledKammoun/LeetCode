class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0 ;i<s.size() ; i++){
            if (s[i]>='A' && s[i]<='Z'){
                s[i]+=(int)'a'-(int)'A' ;
            }
        }
        return s ;
    }
};