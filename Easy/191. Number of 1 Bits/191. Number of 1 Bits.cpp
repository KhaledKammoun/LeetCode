class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = std::bitset<32>(n).to_string(); 
        int sum = 0 ;
        for (auto c : s)
        if (c=='1')
            sum+=1 ;
        return sum ;
    }
};