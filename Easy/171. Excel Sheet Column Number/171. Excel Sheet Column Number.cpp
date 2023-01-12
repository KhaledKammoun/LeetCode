class Solution {
public:
    int titleToNumber(string columnTitle) {
        int som = 0 ,l=columnTitle.size();
        for (int i = 0 ;i<l ; i++){
            som+=pow(26,l-1-i)*((int)columnTitle[i]-(int)'A'+1) ;
        }
        return som ;
    }
};