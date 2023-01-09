class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        int res = 0, flag = 0;
        
        for(char ch: allowed)
            arr[ch-'a'] = 1;    //marking all letters which are allowed
        
        for(string w: words){
            flag = 0;
            for(char ch : w) {
                if(arr[ch-'a'] == 0) {
                    flag = 1;      //to know that this word is invalid
                    break;
                }
            }
            if(flag) 
                continue;
            else
                res += 1;
        }
        return res;
    }
};