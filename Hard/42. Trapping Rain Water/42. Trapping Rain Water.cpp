class Solution {
public:
    int trap(vector<int>& v) {
        int i = 0 , j = v.size()-1 ,sum=0,sl=0,sr=0;
        while (i<j){
            if (v[i]<=v[j]){
                sum+=max(0,sl-v[i]) ;
                sl=max(sl,v[i++]) ;
            }
            else {
                sum+=max(0,sr-v[j]) ;
                sr=max(sr,v[j--]) ;
            }
        }
        return sum ;
    }
};
