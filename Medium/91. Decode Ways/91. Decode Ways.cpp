#include <bits/stdc++.h>
#include <fstream>

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define newL cout<<endl
#define ll long long
using namespace std ;

std::map<std::pair<int, int>, bool> visited;
    int result = 0;
        
    bool dfs(int index, int index2, const std::string& s) {
        if (index >= s.size()) return true;

        if (visited[{index, index2}]) {
            result++ ;
            return true;
        }

        if (s[index] == '0') {
            visited[{index, index2}] = false;
            return false;
        }

        if (index == s.size() - 1) {
            result++;
            visited[{index, index2}] = true;
            return true;
        }

        bool validPath = dfs(index, index2, s);

        if (validPath) {
            result++;
        }

        visited[{index, index + 1}] = validPath;

        return validPath;
    }

    int numDecodings(const std::string& s) {
        if (s.empty()) return 0;
        dfs(0, 0, s);
        dfs(0, 1, s);
        return result;
    }

int main() {
    cout<<numDecodings("11106") ;
}