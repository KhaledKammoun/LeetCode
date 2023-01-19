class Solution {
public:
    int differenceOfSum(vector<int>& t) {
        int e = 0 ,d = 0 ;
        for (int i= 0 ;i<t.size();i++){
            int x = t[i] ;
            while (x!=0){
                d+=x%10 ;
                x/=10 ;
            }
            e+=t[i] ;
        }
        return abs(e-d) ;
    }
    
};