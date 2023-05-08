class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size() ,l = 0;
        vector<int>v ;
        if (k>size)
            return v ;
        deque<int>q ;
        for (int r = 0 ;r<size ; r++){
            while (!q.empty() && (q.back()<nums[r])){
                q.pop_back() ;
            }
            q.push_back(nums[r]) ;
            if (r>=k-1){
                v.push_back(q.front()) ;
                if(q.front()==nums[l])
                    q.pop_front() ;
                l++ ;
            }
        }
        return v ;
    }
};