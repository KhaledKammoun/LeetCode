class Solution {
public:
    int alternateDigitSum(int n) {
        int som = 0 ,i , x = n;
        while (x!=0){ // calculate length of n 
            x/=10 ;
            i++ ;
        }
        (i%2==0) ? i=-1 : i=1 ;
        while (n!=0){
            som+=(n%10)*i ;
            n/=10 ;
            i*=-1 ;
        }
        return som ;
    }
};