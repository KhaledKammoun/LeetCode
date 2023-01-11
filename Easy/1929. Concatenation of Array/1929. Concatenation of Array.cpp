#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> concatenated;

        // Resize concatenated vector to twice the size of the input vector
        concatenated.resize(nums.size() * 2);

        // Copy elements from input vector to concatenated vector
        for (int i = 0; i < nums.size(); i++) {
            concatenated[i] = nums[i];
        }

        // Copy elements from input vector to second half of concatenated vector
        for (int i = 0; i < nums.size(); i++) {
            concatenated[i + nums.size()] = nums[i];
        }

        return concatenated;
    }
};