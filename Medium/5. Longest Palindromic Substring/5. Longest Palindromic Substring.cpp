class Solution {
public:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i); // Odd-length palindrome
            int len2 = expandAroundCenter(s, i, i + 1); // Even-length palindrome
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
