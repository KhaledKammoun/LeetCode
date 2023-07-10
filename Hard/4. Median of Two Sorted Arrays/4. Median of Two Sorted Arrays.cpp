class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size() ;
        int lA = 0, rA = n-1, lB = 0, rB = m-1 ;
        while (lA <= rA){
            int i = (lA + rA)/2, j = (lB + rB)/2 ;
            if (i==0 || i==n-1 || (A[i+1]>=B[j] && B[j+1] > A[i])){
                if ((n+m)%2!=0)
                    return max(A[i],B[j]) ;
                else{
                    if (i<0 || i>=n){
                        return B[j]+B[j-1] ;
                    }
                    else if (j<0 || j>=m){
                        return A[i]+A[i-1] ;
                    }
                    else{
                        return (A[i]+B[j])/2 ;
                    }
                }
            }else if (A[i+1]<B[j]){
                rB = j - 1 ;
                lA = i + 1 ;
            }
            else{
                lB = j + 1 ;
                rA = i - 1 ;
            }
        }
        return 0.0 ;
    }
};
