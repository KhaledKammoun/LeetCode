class Solution {
public:
    int findComplement(int num) {
        int k = 0 ;
        int bits = sizeof(num) * 8 - __builtin_clz(num) ;
        for (int i = 0 ;i < bits ; i++){
            if (!(num&1))
                k+=pow(2,i) ;
            num=num>>1 ;
        }
        return k ;
    }
};