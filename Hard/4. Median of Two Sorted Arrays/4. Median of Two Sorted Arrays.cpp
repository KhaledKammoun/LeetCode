class Solution {
public:
    static int binarySearch(const vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == target) {
                return mid;  // Found the target
            } else if (arr[mid] < target) {
                low = mid + 1;  // Target is in the right half
            } else {
                high = mid - 1;  // Target is in the left half
            }
        }
        return (low > high) ? low : high;
    }

    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), n1 = B.size();
        int lA = 0, rA = n - 1;
        while (lA <= rA) {
            int m = (lA + rA) / 2;
            
            // Find A[m] position in B
            int m2 = binarySearch(B, A[m]);
            int l = m + m2, r = (n - m - 1) + (n1 - m2);
            if (abs(l - r) == 1 && (n1 + n) % 2 == 0) {
                return (l > r) ? (A[m] + B[m2 - 1]) / 2.0 : (A[m] + B[m2]) / 2.0;
            } else if (((n1 + n) % 2 != 0)) {
                double f = B[m2] ;
                return f;
            }
            if (l <= r)
                lA = m + 1;
            else
                rA = m - 1;
            m = (lA + rA)/2 ;
            if (m < 0 || m >= n || n == 0) {
                swap(A, B);
                lA = 0;
                n = A.size();
                rA = n - 1;
                n1 = B.size();
            }
        }
        return 0.0;
    }
};
