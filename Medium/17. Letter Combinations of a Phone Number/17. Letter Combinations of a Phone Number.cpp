class Solution {
public:
    unordered_map<char, string> m {
        {'2', "abc"},  {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    } ;
    vector<string> result ;
    void dfs(string &digits, string answer, int i){
        if (i == digits.size()){
            result.push_back(answer) ;
            return ;
        }
        for (int j = 0; j<m[digits[i]].size(); j++){
            answer+=m[digits[i]][j] ;
            dfs(digits, answer, i+1) ;
            answer.erase(answer.end() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return result ;
        dfs(digits, "", 0) ;
        return result; 
    }
};