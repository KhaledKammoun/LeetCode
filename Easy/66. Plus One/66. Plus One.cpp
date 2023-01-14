class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size() ;
        if (l==0)
            return digits ;
        if (digits[l-1]!=9){
            digits[l-1]++ ;
            return digits ;
        }
        else {
            int i = l-1 ;
            while (digits[i]==9){
                digits[i]=0 ;
                i-- ;
                if (i==-1)
                    break ;
            }
            if (i==-1)
                digits.insert(digits.begin(),1) ;
            else
                digits[i]++ ;
            return digits;
        }
        
    }
};