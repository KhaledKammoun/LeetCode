class Solution {
public:
    int mySqrt(int x) {
        long long  i = 0 ;
        while(i*i<x)
            i++ ;
        if (i*i>x)
            return i-1 ;
        return i ;
    }
};