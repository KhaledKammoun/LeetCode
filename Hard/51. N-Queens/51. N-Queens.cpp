#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    void dfs(int n, int i, int j, int n_queen, vector<string> &board, vector<pair<int, int>> &board_list) {
        if (i >= n && j >= n && n_queen == n) {
            result.push_back(board);
            return;
        } else if (i >= n || j >= n) {
            return;
        }
        for (int i_new = i; i_new < n; i_new++) {
            for (int j_new = j; j_new < n; j_new++) {
                int test = false;
                for (auto x : board_list) {
                    int i_diff = abs(i_new - x.first), j_diff = abs(j_new - x.second);
                    if (i_diff + j_diff == 1 || i_new == x.first || j_new == x.second) {
                        test = true;
                        break;
                    }
                }
                if (test) {
                    board[i_new][j_new] = 'Q';
                    board_list.push_back(make_pair(i_new, j_new));
                    
                    dfs(n, i_new, j_new , n_queen , board, board_list);
                    i_new -= 1;
                    j_new -= 2;
                    n_queen -= 1;
                    board_list.pop_back();
                    board_list.push_back(make_pair(i_new, j_new));
                    
                    dfs(n, i_new, j_new, n_queen, board, board_list);
                    i_new -= 2;
                    j_new -= 1;
                    n_queen -= 1;
                    board_list.pop_back();
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<pair<int, int>> board_list;
        int i = 0, j = 0, n_queen = 0;
        dfs(n, i, j, n_queen, board, board_list);
        return result;
    }
};
