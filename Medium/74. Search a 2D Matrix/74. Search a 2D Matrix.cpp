class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size() ;
        int l = 0, r =m-1,u=0,d =n-1, m_vert = -1;
        while (u<=d){
            int x = u + (d-u)/2 ;
            if (matrix[x][0] <= target && matrix[x][m-1] >= target){
                m_vert = x ;
                break ;
            }
            else if (matrix[x][0]>target)
                d = x-1 ;
            else if (matrix[x][0]<target)
                u = x+1 ;
        }
        if (m_vert == -1)
            return false ;
        while (l<=r){
            int m = l + (r-l)/2 ;
            if (matrix[m_vert][m]>target)
                r = m-1 ;
            else if (matrix[m_vert][m]<target)
                l = m+1 ;
            else
                return true ;
        }
        return false ;
    }
};