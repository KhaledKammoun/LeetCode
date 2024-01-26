class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size() ;
        int min_val = prices[0], max_val = prices[0] ;
        int result = 0 ;
        for (int i = 1; i < length; i++){
            if (prices[i] < min_val){
                min_val = prices[i] ;
                max_val = min_val ;
            }
            else{
                max_val = prices[i] ;
                result = max(result, max_val - min_val) ;
            }
        }
        return result ;
    }
};