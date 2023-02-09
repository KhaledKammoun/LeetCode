class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> m ;
        int sum = 0 ;
        for (int i = 0 ; i<jewels.size() ; i++)
            m[jewels[i]]++ ;
        for (int i = 0 ; i<stones.size() ; i++){
            if (m[stones[i]])
                sum++;
        }
        return sum;
    }
};