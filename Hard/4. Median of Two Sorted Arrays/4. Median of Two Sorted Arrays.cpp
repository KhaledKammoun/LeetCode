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
            if (m < 0 || m >= n || n == 0) {
                swap(A, B);
                lA = 0;
                n = A.size();
                rA = n - 1;
                n1 = B.size();
            }
            // Find A[m] position in B
            int m2 = binarySearch(B, A[m]);
            int l = m + m2, r = (n - m - 1) + (m - m2 - 1);
            if ((m + n) % 2 == 0 && abs(l - r) == 1) {
                return (l > r) ? (A[m] + B[m2 - 1]) / 2.0 : (A[m] + B[m2]) / 2.0;
            } else if ((m + n) % 2 != 0 && l - r == 0 && l == (m + n) / 2) {
                return B[m];
            }
            if (l < r)
                lA = m + 1;
            else
                rA = m - 1;
        }
        return 0.0;
    }
};
