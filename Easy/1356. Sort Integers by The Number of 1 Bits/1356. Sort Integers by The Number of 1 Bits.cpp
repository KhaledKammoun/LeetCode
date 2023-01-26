class Solution {
public:
    static  bool compare(int u ,int u1){
        int n=__builtin_popcount(u) ,n1=__builtin_popcount(u1) ;
        if (n!= n1)
            return n<n1 ;
        else 
            return u<u1 ;
    }
    vector<int> sortByBits(vector<int>& v) {
        sort (v.begin(),v.end(), Solution::compare) ;
        return v ;
    }
};