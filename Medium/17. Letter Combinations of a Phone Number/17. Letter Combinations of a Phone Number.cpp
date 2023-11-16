class Solution {
public:
    std::unordered_map<char, pair<int,char>> m {
        {'2', make_pair(3,'a')}, {'3', make_pair(3,'d')}, {'4', make_pair(3,'g')}, {'5', make_pair(3,'j')},
        {'6', make_pair(3,'m')}, {'7', make_pair(4,'p')}, {'8', make_pair(3,'t')}, {'9', make_pair(4,'w')}
    };
    vector<string> result ;
    void dfs(string s,string sNum, int startS, int &num){
        if (startS == s.size())
            return ;
        if (result.size()!=0)
            num = 1 ;
        for (int i = num ; i<m[sNum[startS]].first ; i++){
            if (i != 0)
                s[startS]++ ;
            result.push_back(s) ;
            dfs(s, sNum, startS + 1,num) ;
            s[startS]
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return result ;
        string s = "" ;
        for (int i = 0 ;i<digits.size() ; i++)
            s+=m[digits[i]].second ;
        int start = 0 ;
        
        dfs(s, digits, 0,start) ;
        return result ;
    }
};