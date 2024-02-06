class Solution {
public:
    int visited[201][201] = {0} ;
    vector<vector<int>> result ;
    void dfs(vector<vector<int>>& heights, int n, int m, int i, int j){
        if (i >= n || j >= m || (i < n && j < m && (visited[i][j] == 4 || visited[i][j] == 1)))
            return ;
        else if ((i+1 == n) || (j+1 == m) || (i+1 < n && heights[i+1][j] <=heights[i][j]) ||  (j + 1 < m && heights[i][j+1] <=heights[i][j])){
            visited[i][j]+=2 ;
            if (visited[i][j] == 4){
                result.push_back(vector<int>{i, j}) ;
            }
            return ;
        }
        else{
            visited[i][j] = 1 ;
            if (j + 1 < m && heights[i][j+1] > heights[i][j])
                dfs(heights, n, m, i, j+1) ;
            else 
                return ;
            if (i + 1 < n && heights[i+1][j] > heights[i][j])
                dfs(heights, n, m, i+1, j) ;
            else 
                return ;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size() ;
        for (int j = 0; j < m; j++){
            dfs(heights, n, m, 0, j) ;
            dfs(heights, n, m, m - 1, m - 1 - j) ;
        }
        for (int i = 0; i < n; i++){
            dfs(heights, n, m, i, 0) ;
            dfs(heights, n, m, n - 1 - i, n - 1) ;
        }
        return result ;
    }
};