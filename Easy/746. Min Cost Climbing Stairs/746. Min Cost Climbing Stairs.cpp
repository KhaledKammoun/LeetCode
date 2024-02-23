class Solution {
public:
    int dfs(vector<int>& cost,vector<int>&memo, int start) {
        if (start >= cost.size()){
            return 0 ;
        }
        if (memo[start] != -1)
            return memo[start] ;

        memo[start] = cost[start] + min(dfs(cost, memo, start + 1),dfs(cost, memo,start + 2)) ;
        
        return memo[start] ;

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min(dfs(cost, memo, 0), dfs(cost, memo, 1)) ;
    }
};