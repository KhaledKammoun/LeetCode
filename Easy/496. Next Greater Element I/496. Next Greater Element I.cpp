class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int t[10001]={-1} ;
        t[nums2[nums2.size()-1]]=-1 ;
        stack<int>s ;
        s.push(nums2[nums2.size()-1]) ;
        for (int i = nums2.size()-2 ; i>=0 ; i--){
            while (!s.empty() &&s.top()<nums2[i])
                s.pop() ;
            if (s.empty())
                t[nums2[i]]=-1 ;
            else 
                 t[nums2[i]]=s.top() ;
            s.push(nums2[i]) ;
        }
        vector<int> v;
        for (int i = 0 ;i<nums1.size() ; i++){
            v.push_back(t[nums1[i]]) ;
        }
        return v ;
    }
};