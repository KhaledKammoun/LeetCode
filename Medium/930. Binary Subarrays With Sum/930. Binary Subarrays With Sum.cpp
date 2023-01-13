class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        const int N=3*1e4 ;
        int  n = v.size() ,sum = (v[0]==goal);
        int occ[N]={0} ;
        occ[0]=1 ;
        occ[v[0]]++ ;
        for (int i = 1 ; i< n ;i++){
            v[i]+=v[i-1] ;
            if (v[i]>=goal)
                sum += occ[v[i]-goal] ;
            occ[v[i]]++ ;
        }
        return sum ;
    }
};