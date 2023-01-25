class Solution {
public:
    int numberOfSteps(int n) {
        if (n==0)
            return 0 ;
        int bits = sizeof(n) * 8 - __builtin_clz(n); //number of bits in the n binary representation 
        int n1 = __builtin_popcount(n) ;//the number of 1's in the binary representation 

        return bits+n1-1 ;
    }
};