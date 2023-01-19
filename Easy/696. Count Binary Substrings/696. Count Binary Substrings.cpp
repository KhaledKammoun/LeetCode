class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev_len = 0, cur_len = 1, c = 0;
        for (int i = 1 ;i<s.size() ; i++){
            if (s[i-1]==s[i])
                cur_len++ ;
            else {
                prev_len = cur_len ;
                cur_len = 1 ;
            }
            if (prev_len>=cur_len)
                c++ ;
        }
        return c;
    }
};
