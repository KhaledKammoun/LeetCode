class Solution {
public:
    std::unordered_map<std::string, std::string> m {
        {"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"},
        {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}
    };
    vector<string> result ;
    void dfs(string &s,string& sNum, int startS,int startNum){
        if (startS == s.size())
            return ;
        for (int i = startNum ; i<m[sNum.substr(startS, 1)].size() ; i++){
            result.push_back(s) ;
            s[startS]++ ;
            dfs(s, sNum, startS + 1, startNum + 1) ;
            s[startS]-- ;
        }
    }
    vector<string> letterCombinations(string digits) {
        string s = "" ;
        for (int i = 0 ;i<digits.size() ; i++)
            s+=m[digits.substr(i,1)][0] ;
        dfs(s, digits, 0,0) ;
        return result ;
    }
};