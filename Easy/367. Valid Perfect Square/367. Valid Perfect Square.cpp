class Solution {
public:
    bool isPerfectSquare(int num) {
        float f = pow(num,0.5) ;
        if ((f-(int)f)!=0)
            return 0 ;
        
        return (f*f)==num ;
    }
};