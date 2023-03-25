class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& spd) {
        map<int,int>v ;
        for (int i = 0 ; i<pos.size() ; i++)
            v[pos[i]]=spd[i] ;
        
        stack<pair<int,int>>s ;
        s.push(*v.rbegin()) ;
        for (auto it = next(v.rbegin()); it != v.rend(); ++it) {
            double time1 = (double)(t - it->first) / it->second;
            double time2 = (double)(t - s.top().first) / s.top().second;
            if (time1 > time2)
                s.push(*it) ;
        }
        return s.size() ;
    }   
};
