class TimeMap {
private:
    unordered_map<string,vector<pair<string,int>>>m ;
public:
    TimeMap() {
        m=unordered_map<string,vector<pair<string,int>>>() ;
    }
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(value,timestamp)) ;
    }
    string get(string key, int timestamp) {
        if (m[key].size()==0)
            return "" ;
        int l = 0, r = m[key].size()-1 ;
        while (l<=r){
            int mid = (l+r)/2 ;
            if (m[key][mid].second>timestamp)
                r = mid-1 ;
            else if (m[key][mid].second<timestamp)
                l = mid + 1 ;
            else 
                return m[key][mid].first ;
        }
        if (r >= 0)
            return m[key][r].first;
        else
            return "";
    }

};