class Solution {
public:
    bool isPowerOfFour(int n) {
        /*1 = 00000001
        4 = 00000100
        16= 00010000
        64= 01000000*/
        //return (n>0 && (n&(n-1))==0 && (sizeof(n) * 8 - __builtin_clz(n))%2!=0) ;
        return (n>0) &&(n & n - 1) == 0 && (n - 1) % 3 == 0 ;
    }
};