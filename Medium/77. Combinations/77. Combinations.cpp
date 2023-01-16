class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v ;
        for (int i = 1 ; i<=(1<<n) ;i++){
            bitset<20>b(i) ;
            int sum_1 = b.count() ;
            if (sum_1==k){
                vector<int> v1 ;
                string s= b.to_string();
                for(int j = 20-n ; j<20 ;j++){
                    if (s[j]=='1')
                        v1.push_back(j-20+n+1) ;
                }
                if (v1.size()>0)
                    v.push_back(v1) ;
            }
        }
        return v ;
    }
};
