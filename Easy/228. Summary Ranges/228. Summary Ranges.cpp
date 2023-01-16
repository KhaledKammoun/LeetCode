class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        int n = v.size() ;
        vector <string> s ;
        if (v.empty())
            return s ;
        if (n==1){
            s.push_back(to_string(v[0])) ;
            return s ;
        }
        int i  = 0 ;
        for (int j = 1 ; j<n ; j++){
            long long c = 0 ;
            if (v[j]> 0 &&v[j-1]<0)
                c=2 ;
            else
                c =v[j]-v[j-1] ;

            if (c!=1){
                if (v[i]==v[j-1])
                    s.push_back(to_string(v[i]));
                else
                    s.push_back(to_string(v[i])+"->"+to_string(v[j-1]) );
                i = j ;
                if (j==n-1)
                    s.push_back(to_string(v[j]) );
            }
            else {
                if (j==n-1)
                    s.push_back(to_string(v[i])+"->"+to_string(v[j]) );
            }
        }
        return s ;
    }
};