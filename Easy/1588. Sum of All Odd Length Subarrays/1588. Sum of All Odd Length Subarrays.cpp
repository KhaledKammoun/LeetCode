class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {
        unordered_map<int,vector<int>>m ;
        int som=0 ;
        for (int i = 0 ; i<v.size() ; i++){
            m[i]={v[i]} ; //first case of the vector is initialised but the sum of its elements
            for (int j =0 ; j<i+1 ; j++){
                m[j].push_back(v[i]) ;
                if (i!=j)
                    m[j][0]+=v[i] ;
                if ((m[j].size()-1)%2!=0)
                    som+=m[j][0] ;

            }
        }
        return som ;
    }
};