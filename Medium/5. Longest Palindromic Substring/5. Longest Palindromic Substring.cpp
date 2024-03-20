class Solution {
public:
    bool verifPalindrom(string s) {
        int i = 0;
        while (i < s.size() / 2) {
            if (s[i] == s[s.size() - i - 1])
                i++;
            else
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        vector<string> v(26, "");
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'] = (i > 0) ? v[s[i - 1] - 'a'] + s[i] : string(1, s[i]);

            if (verifPalindrom(v[s[i] - 'a']) && v[s[i] - 'a'].size() > result.size())
                result = v[s[i] - 'a'];
        }
        return result;
    }
};
