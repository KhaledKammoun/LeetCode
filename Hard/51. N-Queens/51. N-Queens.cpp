#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    void dfs(int n, int row, vector<string> &board, int board_list[], int diff_list[]) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(n, row, i, board, board_list, diff_list)) {
                board[row][i] = 'Q';
                board_list[i] = 1;
                diff_list[abs(row - i)] = 1;

                dfs(n, row + 1, board, board_list, diff_list);

                // Backtrack
                board[row][i] = '.';
                board_list[i] = -1;
                diff_list[abs(row - i)] = -1;
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string> &board, int board_list[], int diff_list[]) {
        if (board_list[col] == -1 && diff_list[abs(row - col)] == -1) {
            return true;
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int board_list[n];
        int diff_list[n];
        fill_n(board_list, n, -1);
        fill_n(diff_list, n, -1);

        dfs(n, 0, board, board_list, diff_list);

        return result;
    }
};
