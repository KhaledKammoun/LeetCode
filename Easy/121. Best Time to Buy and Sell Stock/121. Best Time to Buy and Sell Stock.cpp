class Solution {
public:
    int maxProfit(vector<int>& v) {
        int l=0 , r= 1 ,diff=0 ;
        while (r<v.size()){
            if (v[l]>=v[r]){
                l=r;
                r++;
            }
            else {
                diff=max(diff,v[r]-v[l]) ;
                r++;
            }
        }
        return diff ;
    }
};