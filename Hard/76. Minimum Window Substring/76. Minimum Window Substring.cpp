class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return "";
        }

        unordered_map<char, int> tab_t, tab_s;
        for (char c : t) {
            tab_t[c]++;
        }

        int l = 0, ma = 0, len = INT_MAX;
        pair<int, int> p;

        for (int r = 0; r < s.size(); r++) {
            if (tab_t.count(s[r])) {
                tab_s[s[r]]++;
                if (tab_s[s[r]] == tab_t[s[r]]) {
                    ma++;
                }
            }

            while (ma == tab_t.size()) {
                if (len > r - l + 1) {
                    len = r - l + 1;
                    p = {l, r};
                }

                if (tab_t.count(s[l])) {
                    tab_s[s[l]]--;
                    if (tab_s[s[l]] < tab_t[s[l]]) {
                        ma--;
                    }
                }

                l++;
            }
        }

        if (len == INT_MAX) {
            return "";
        }

        return s.substr(p.first, len);
    }
};