class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        
        string result = "";
        int digitsToRemove = k;

        for (char digit : num) {
            while (!result.empty() && result.back() > digit && digitsToRemove > 0) {
                result.pop_back();
                digitsToRemove--;
            }
            
            if (result.empty() && digit == '0')
                continue;
            
            result.push_back(digit);
        }

        while (digitsToRemove > 0 && !result.empty()) {
            result.pop_back();
            digitsToRemove--;
        }

        if (result.empty())
            return "0";

        return result;
    }
};