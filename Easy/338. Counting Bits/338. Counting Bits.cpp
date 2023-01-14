class Solution {
public:
    vector<int> countBits(int num) {
        vector <int>v{0} ;
        for (int i = 1 ; i<(num+1) ; i++){
            v.push_back(v[i&(i-1)]+1) ;
        }
        return v ;
    }
};