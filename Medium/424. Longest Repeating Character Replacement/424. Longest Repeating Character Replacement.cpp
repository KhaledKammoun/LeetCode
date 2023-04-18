class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), sum = 0, i = 0, x = 0;
        int count[26]={0} ;
        for (int j = 0 ; j<n ; j++){
            x = max(x,++count[s[j]-'A']) ;
            while (j-i+1-x>k){
                count[s[i++]-'A']--;
            }
            sum = max(sum,j-i+1) ;
        }
        return sum;
    }
};
