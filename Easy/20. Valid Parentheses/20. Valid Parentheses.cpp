class Solution {
public:
    bool isValid(string s) {
    int n = s.length() ;
    vector <char>v {s[0]} ;
    for (int i = 1 ; i<n ; i++){
        if (v.size()>0){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
                v.push_back(s[i]) ;
            else {
                int code = (int)s[i] ;
                if (s[i]==')')
                    code-- ;
                else
                    code-=2 ;
                if (((int)v[v.size()-1])==code)
                    v.pop_back() ;
                else
                    return false ;
            }
        }
        else 
            v.push_back(s[i]) ;
    }
    if (v.size()>0)
        return false ;
    else 
        return true ;
    }
};