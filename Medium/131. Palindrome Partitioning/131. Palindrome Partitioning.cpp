class Solution {
public:
    vector<vector<string>> result ;
    void backtracking(vector<string> &v, int start, int length){
        bool is_palindrome = true ;
        for (auto c : v){
            string rev_s = c ;
            reverse(rev_s.begin(), rev_s.end()) ;
            if (rev_s != c){
                is_palindrome = false ;
                break ;
            }
        }
        if (is_palindrome)
            result.push_back(v) ;
        
        for (int i = start ; i<length - 1 ;i++){
            string new_s = v[i], new_s1 = v[i+1];
            v[i]+=v[i+1] ;
            v.erase(v.begin()+i+1) ;
            backtracking(v,i, length- 1) ;
            v[i] = new_s ;
            v.insert(v.begin() + i + 1, new_s1) ;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v ;
        for (auto c : s) {
            string x(1, c);
            v.push_back(x);
        }
        backtracking(v, 0, v.size()) ;
        return result ;
    }
};