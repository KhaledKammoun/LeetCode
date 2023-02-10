class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1==num2)
            return (num1!=0) ? 1 :0 ;
        int mi = min(num1,num2) ;
        int ma = max(num1,num2) ;
        int c = 0 ;
        while (mi!=0 && ma!=mi){
            int min_copy = mi ;
            c+=ma/mi ;
            mi = ma%mi ;
            ma = min_copy ;
            
        }
        return c ;
    }
};