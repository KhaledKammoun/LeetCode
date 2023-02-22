class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size() ;
        if (n==1)
            return {{strs[0]}} ;
        vector<vector<string>> v ;
        unordered_map<string,int> m ;
        int x = 0 ;
        for (int i =0 ; i<n ; i++){
            string s = strs[i] ;
            sort(s.begin(),s.end()) ;
            if (!m.count(s)){
                v.push_back({strs[i]}) ;
                
                m[s]=x ;
                x++ ;
            }
            else {
                v[m[s]].push_back(strs[i]) ;
            }
        }
        return v ;
    }
};