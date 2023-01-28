class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0)
            return 1 ;
        int k = 0 ;
        int bits = sizeof(n) * 8 - __builtin_clz(n); ;
        for (int i = 0 ;i < bits ; i++){
            if (!(n&1))
                k+=pow(2,i) ;
            n=n>>1 ;
        }
        return k ;
    }
};