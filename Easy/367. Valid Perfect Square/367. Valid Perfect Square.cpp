class Solution {
public:
    bool isPerfectSquare(int num) {
        float f = pow(num,0.5) ;
        if ((f-(int)f)!=0)
            return false ;
        
        return (f*f)==num ;
    }
};