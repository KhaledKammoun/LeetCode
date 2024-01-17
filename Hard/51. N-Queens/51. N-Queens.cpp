#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    void dfs(int n, int row, vector<string> &board, bool *board_list, vector<pair<int,int>> &diff_list) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(n, row, i, board, board_list, diff_list)) {
                board[row][i] = 'Q';
                board_list[i] = true;

                diff_list.push_back(make_pair(row, i));
                dfs(n, row + 1, board, board_list, diff_list);
                diff_list.pop_back();
                board[row][i] = '.';
                board_list[i] = false;
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string> &board, bool *board_list, vector<pair<int, int>> &diff_list) {
        if (board_list[col])
            return false;
        for (auto c : diff_list) {
            int row_diff = abs(c.first - row), col_diff = abs(c.second - col);
            if (row_diff == col_diff)
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        bool board_list[9] = {false};
        vector<pair<int, int>> diff_list;
        dfs(n, 0, board, board_list, diff_list);
        return result;
    }
};
