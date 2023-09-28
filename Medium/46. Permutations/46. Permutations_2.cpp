class Solution {
public:
    vector<vector<int>> result ;
    void generatePermutations(vector<int>& nums, int start) {
    int nums_size = nums.size() ;
    if (start == nums_size - 1){
        result.push_back(nums) ;
        return ;
    }
    for (int i = start ; i < nums_size ; i++){
        swap(nums[i],nums[start]) ;
        generatePermutations(nums, start + 1) ;
        swap(nums[i],nums[start]) ;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    generatePermutations(nums, 0);
    return result;
}
};