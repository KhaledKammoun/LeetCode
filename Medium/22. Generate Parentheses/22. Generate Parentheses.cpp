class Solution {
public:
    void backtrack(vector<string>&v, string&s ,int n , int open , int close){
            if (open==close && close==n){
                v.push_back(s) ;
                return ;
            }
            if (open<n){
                s.append(1,'(') ;
                backtrack(v,s,n,open+1,close) ;
                s.erase(s.length()-1) ;
            }
            if (close<open){
                s.append(1,')') ;
                backtrack(v,s,n,open,close+1) ;
                s.erase(s.length()-1) ;

            }
        }
    vector<string> generateParenthesis(int n) {
        string s ;
        vector<string>v ;
        backtrack(v,s,n,0,0) ;
        return v ;
    }
};