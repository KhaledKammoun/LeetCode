class Solution {
public:
    string result = "";
    void expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            right++ ;
            left-- ;
        }
        if (right - left - 1 > result.size()) {
            result = s.substr(left+1, right - left - 1) ;
        }
        return ;
    }
    string longestPalindrome(string s) {
        int n = s.size() ;
        for(int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i);
            expandAroundCenter(s, i, i+1);
        }
        return result ;
    }
};
