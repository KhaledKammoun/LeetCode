class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int k = 1, n = piles.size();
        while (l <=r){
            long long c = 0 ;
            int  m = (l+r)/2 ;
            for (int i = 0 ; i<n ; i++) {
                c+=((piles[i]/m)+((piles[i]%m)!=0)) ;
            }
            if (c<=h){
                k = m ;
                r = m -1 ;
            }
            else 
                l = m + 1 ;
        }
        return k ;
    }
};