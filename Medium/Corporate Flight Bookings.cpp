class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> t1(n+1,0);
        for (auto & b : bookings) {
            t1[b[0]-1]+=b[2] ;
            t1[b[1]]-=b[2] ;
        }
        for (int i = 1 ;i< n; i++)
            t1[i]+=t1[i-1] ;
        return {t1.begin() ,t1.end()-1} ;
        
    }
};