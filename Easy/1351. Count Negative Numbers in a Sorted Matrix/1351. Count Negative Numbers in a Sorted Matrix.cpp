class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0,n = grid.size(), m = grid[0].size() ;
        for (int i = 0 ; i<n*m ; i++){
            if (grid[i / m][i % m] < 0)
                sum++ ;
        }
        return sum ;
    }
};