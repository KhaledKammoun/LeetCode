class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int l = bits.size() ;
        if (l==1)
            return true ;
        if (l==2)
            return bits[l-1]==bits[l-2] ;

        int i =0 ;
        while (i<l-1){
            if (bits[i]==1)
                i+=2 ;
            else 
                i++ ;  
        }
        if (i==(l-1))
                return true ;
            else
                return false ;
    }
};