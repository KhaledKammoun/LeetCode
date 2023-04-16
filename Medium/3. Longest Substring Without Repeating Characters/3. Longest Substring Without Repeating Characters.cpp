class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0,j=0,sum=0,n=s.size();
        if (n<=1)
            return n ;
        bool tab[256]={false};
        while (j<n){
            while (tab[s[j]]==true){
                tab[s[i++]]=false;
            }
            sum=max(sum,j-i+1) ;
            tab[s[j++]]=true;  
        }
        return sum ;
    }
};
