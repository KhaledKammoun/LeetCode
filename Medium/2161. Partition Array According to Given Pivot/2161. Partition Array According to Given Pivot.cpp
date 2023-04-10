class Solution {
public:
    vector<int> pivotArray(vector<int>& v, int p) {
        vector<int>less(v.size(),0) ;
        vector<int>equal(v.size(),0) ;
        vector<int>great(v.size(),0) ;
        int i = 0 , j = 0 , k = 0 ;
        for (int c = 0 ; c< v.size() ; c++){
            if (v[c]<p)
                less[i++]=v[c] ;
            else if (v[c]>p)
                great[j++]=v[c] ;
            else 
                equal[k++]=v[c] ;
        }
        for (int c = 0 ; c<v.size() ; c++){
            if (c<i)
                v[c]=less[c] ;
            else if (c<i+k)
                v[c]=equal[c-i] ;
            else
                v[c]=great[c-i-k] ;
        }
        return v ;
    }
};
