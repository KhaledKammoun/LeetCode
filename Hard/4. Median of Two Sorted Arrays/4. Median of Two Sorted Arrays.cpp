class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n == 0 && m == 0)
            return 0.0;
        else if (n == 0 && m > 0)
            return (m % 2 == 0) ? (B[m / 2] + B[m / 2 - 1]) / 2.0 : B[m / 2];
        else if (n > 0 && m == 0)
            return (n % 2 == 0) ? (A[n / 2] + A[n / 2 - 1]) / 2.0 : A[n / 2];

        if (n > m)
            return findMedianSortedArrays(B, A);
        int l = -1, r = n , half = (n+m)/2 ;
        while (l<=r){
            int i = (l + r)/2 ;
            int j =half - i - 2 ;
            int Aleft = (i>=0) ? A[i] : INT_MIN ;
            int Aright = (i+1<n) ? A[i+1] : INT_MAX ;
            int Bleft = (j>=0) ? B[j] : INT_MIN ;
            int Bright = (j+1<m) ? B[j+1] : INT_MAX ;
            if (Aleft<=Bright && Bleft<=Aright){
                if ((n+m)%2==0)
                    return (double)(max(Aleft,Bleft) + min(Aright,Bright))/2 ;
                else
                    return (double)min(Aright,Bright) ;
            }
            else if (Aleft>Bright)
                r = i - 1 ;
            else
                l = i + 1 ;
        }
        return 0.0 ;
    }
    
};
