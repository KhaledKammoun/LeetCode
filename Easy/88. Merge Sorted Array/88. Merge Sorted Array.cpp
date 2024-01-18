class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j =0 ;
        while (j<n && i<m){
            if (nums1[i] > nums2[j]){
                for (int k = m  ; k > i; k--){
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                m++ ;
                j++ ;
            }
            i++ ;
        }
        copy(nums2.begin() + j, nums2.end(), nums1.begin() + m);
    }
};