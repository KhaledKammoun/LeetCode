class Solution {
public:
    void duplicateZeros(vector<int>& v) {
        if (count(v.begin(),v.end(),0)){
            for (int i = 0 ;i<v.size() ; i++){
                if (v[i]==0){
                    v.insert(v.begin()+i+1 , 0) ;
                    v.pop_back() ;
                    i++ ;
                }
            }
        }
    }
};