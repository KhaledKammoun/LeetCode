class Solution {
public:
    int minimumSum(int num) {
        string s ;
        stringstream ss;
        ss<<num ;
        ss>>s ;
        vector <int> v{(int)s[0]-48,(int)s[1]-48,(int)s[2]-48,(int)s[3]-48} ;
        sort(v.begin(),v.end()) ;
        return (v[0]*10+v[3])+(v[1]*10+v[2]) ;
    }
};