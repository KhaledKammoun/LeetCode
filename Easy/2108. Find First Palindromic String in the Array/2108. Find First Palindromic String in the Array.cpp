class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0 ; i<words.size() ; i++){
            int j = 0 , k = words[i].size()-1 ;
            while (j<k && words[i][j]==words[i][k]){
                j++;k--;
            }
            if (j>=k)
                return words[i] ;
        }
        return "" ;
    }
};