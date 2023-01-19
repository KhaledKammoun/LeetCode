class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n<3)
            return true ;
        int l = n&1;
        n= n>>1 ;
        while (n!=0){
            
            if (l==(n&1))
                return false ;
            else
                l=!l ;
            n= n>>1 ;
        }
        return true;
    }
};