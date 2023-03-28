class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int i =0 , j= v.size()-1 ;
        while(i<j){
            if (v[i]+v[j]<t)
                i++;
            else if (v[i]+v[j]>t)
                j--;
            else 
                return {i+1,j+1} ;
        }
        return {} ;
    }
};
