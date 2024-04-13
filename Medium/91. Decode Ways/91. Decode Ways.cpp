class Solution {
public:
    int result = 0 ;
    void dfs(string &s, int index) {
        if (index>= s.size()-1) {
            result++ ;
            return ;
        }
        if (s[index] != '0') {
            dfs(s, index + 1) ;
        }else {
            return ;
        }
        if (s[index] != '0' && s.substr(index, 2) <= "26") {
            dfs(s,index + 2);
        }
        return ;

    }
    int numDecodings(string s) {
        dfs(s, 0) ;
        return result ;
    }
};