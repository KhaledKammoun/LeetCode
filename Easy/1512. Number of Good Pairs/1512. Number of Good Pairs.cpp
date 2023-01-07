class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int som=0 ;
        int t[101]={0} ;
        map<int,int>m;
        for (int i = 0 ;i<nums.size() ; i++){
            if (t[nums[i]]==0){
                m[nums[i]]=0 ;
                t[nums[i]]=1 ;
            }
            else{
                m[nums[i]]+=+1;
                som+=m[nums[i]] ;
                }
            }

        return som ;
    }
};