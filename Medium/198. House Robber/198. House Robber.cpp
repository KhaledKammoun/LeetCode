class Solution {
public:
    int visited[101] = {0} ;
    int dfs(vector<int> &v, int start) {
        if (start >= v.size())
            return 0 ;
        int max_val = 0 ;
        for (int i = start; i < v.size(); i++) {
            if (!visited[i]){
                visited[i] = v[i] + dfs(v, i + 2) ;
            }
            max_val = max(max_val, visited[i]) ;
        }
        return max_val ;
    }
    int rob(vector<int>& nums) {
        return max(dfs(nums, 0), dfs(nums, 1)) ;
    }
};