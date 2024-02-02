class Solution {
public:
    int nb_max = 0;
    void bfs(vector<vector<int>>& grid,vector<vector<bool>> &visit, int n, int m, int i, int j){
        queue<pair<int, int>> q ;
        q.push(make_pair(i, j)) ;
        visit[i][j] = true ;
        int total_visit = 1;
        while (!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop() ;
            vector<pair<int, int>> dir {{0,1}, {-1,0}, {0, -1}, {1,0}};
            for (auto c : dir){
                int row = c.first + i, col = c.second + j ;
                if (row >=0 && row <n && col >= 0 && col <= m && !visit[row][col] && grid[row][col] == 1){
                    q.push(make_pair(row, col)) ;
                    visit[row][col] = true ;
                    total_visit++ ;
                }
                
            }
        }
        nb_max = max(nb_max, total_visit) ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (!grid.size()) 
            return 0 ;
        int rows = grid.size(), cols = grid[0].size() ;
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j< cols; j++){
                if (grid[i][j] == 1 && !visit[i][j]){
                    bfs(grid, visit, rows, cols, i, j) ;
                }
            }
        }
        return nb_max ;
    }
};