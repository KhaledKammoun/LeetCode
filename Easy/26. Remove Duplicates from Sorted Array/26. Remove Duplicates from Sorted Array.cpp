class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if(nums.size()<=1)return 1;

           int i  = 1;  //**** next index in ans part 
           int j = 1;   //*** index to find unique

           while(j<nums.size()){
             if(nums[j]!=nums[j-1]){  //** whenever a change is seen(means new value occurs)
                 nums[i] = nums[j];   //*** put value in ans part
                 i++;                  
             }
               j++;
           }

        return i;
    }
};