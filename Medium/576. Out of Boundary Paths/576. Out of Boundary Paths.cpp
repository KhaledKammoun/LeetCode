class Solution {
public:
    int dfs(int m, int n, int x, int y, int start, int maxMove){
        if (start > maxMove)
            return 0;
        if (x<0 || x>=m || y<0 || y>=n)
            return 1;
        
        return dfs(m,n, x+1,y,start+1, maxMove) + dfs(m,n, x-1,y,start+1, maxMove) + dfs(m,n, x,y+1,start+1, maxMove) + dfs(m,n, x,y-1,start+1, maxMove);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return dfs(m, n, startRow, startColumn, 0, maxMove) ;
    }
};