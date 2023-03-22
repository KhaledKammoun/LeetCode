class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size() ;
        stack<int>s ;
        s.push(n-1);
        vector<int>v(n,0) ;
        for (int i = t.size()-2 ; i>=0 ; i--){
            while (!s.empty() && t[i]>=t[s.top()]){
                s.pop() ;
            }
            if (s.empty())
                v[i]=0 ;
            else 
                v[i]=s.top()-i ;
            s.push(i);
        }
        return v ;
    }
};