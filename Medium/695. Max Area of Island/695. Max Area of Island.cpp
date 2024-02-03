class Solution {
public:
    int max_area = 0 ;
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int rows, int cols, int i, int j){
        visited[i][j] = true ;
        queue<pair<int, int>> q ;
        q.push(make_pair(i, j)) ;
        int area = 1 ;
        while(!q.empty()){

            int curr_row = q.front().first, curr_col = q.front().second ;
            q.pop() ;
            vector<pair<int, int>> diriction {{0,1}, {-1,0}, {0, -1}, {1,0}};
            for (auto x : diriction){
                int new_curr_row = curr_row + x.first ;
                int new_curr_col = curr_col + x.second ;
                if (new_curr_row >=0 && new_curr_row < rows && new_curr_col >=0 && new_curr_col < cols && !visited[new_curr_row][new_curr_col] && grid[new_curr_row][new_curr_col] == 1){
                    q.push(make_pair(new_curr_row, new_curr_col)) ;
                    visited[new_curr_row][new_curr_col] = true ;
                    area++ ;
                }
            }
        }
        max_area = max(max_area, area) ;
        
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (!grid.size())
            return 0 ;
        int rows = grid.size(), cols = grid[0].size() ;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)) ;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 1 && !visited[i][j]){
                    bfs(grid, visited, rows, cols, i, j) ;
                }
            }
        }
        return max_area ;
    }
};