class Solution {
public:
    vector<int> relativeSortArray(vector<int>& v, vector<int>& v1) {
        vector<int>sum ;
        for (int i = 0 ;i<v1.size() ; i++){
            int l = count(v.begin(),v.end(),v1[i]);
            for (int j =0 ; j< l ;j++){
                sum.push_back(v1[i]) ;
            }
        }
        int l = sum.size() ;
        if (sum.size()!=v.size()){
            for (int i =0 ;i<v.size() ;i++){
                if (!count(v1.begin(),v1.end(),v[i])){
                    sum.push_back(v[i]) ;
                }
            }
            sort(sum.begin()+l,sum.end()) ;
        }
        return sum ;
    }
};