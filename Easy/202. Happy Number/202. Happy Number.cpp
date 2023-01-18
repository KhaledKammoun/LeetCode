class Solution {
public:
    bool isHappy(int n) {
        set<int>s ;
        while (n!=1 && s.count(n)==0){
            s.insert(n) ;
            int sum = 0 ,x = n;
            while (x){
                int x1 = x%10 ;
                sum+=(x1 * x1) ;
                x/=10 ;
            }
            n = sum ;
            
        }
        return n==1 ;
    }
};