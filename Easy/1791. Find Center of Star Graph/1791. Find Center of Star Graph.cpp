//Graph methode

class Solution {
public:
    static  const int  N = 10e5 ;
    map<int,vector<int>> v ;
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() ;
        for (int i = 0 ;i<edges.size() ;i++){
            v[edges[i][1]-1].push_back(edges[i][0]-1) ;
            v[edges[i][0]-1].push_back(edges[i][1]-1) ;
        }
        for (map<int,vector<int>>::iterator it = v.begin() ; it !=v.end() ; it++){
            if ((it -> second).size()==n )
                return (it -> first) +1 ;
        }
        return 0 ;
    }
};