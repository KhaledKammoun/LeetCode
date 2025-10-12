#include <bits/stdc++.h>
using namespace std;

//--------------------Macros & Typedefs--------------------
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define ll long long
#define ld long double

//--------------------Constants----------------------------
const ll MOD = 1e9 + 7;
// const int MOD = 998244353; // uncomment if needed
const int N = 505;
const ll INF = 1e18;
const ll MIN = -1e18;
const ll PRIME = 1000003;

//--------------------Solve Function-----------------------
void solve() {
    // Example input template
    int n;
    cin >> n;
    
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) v1.push_back(i + 1);
        else v2.push_back(i + 1);
    }
    
    if (v1.size() == 1) cout << v1[0];
    else cout << v2[0];
}

//--------------------Main Function------------------------
int main() {
    FAST;

    int t = 1;
    // cin >> t; // uncomment if multiple test cases
    while (t--) solve();

    return 0;
}

//--------------------Notes & Reminders-------------------
// 1. Check for int overflows
// 2. Watch array/vector bounds
// 3. Handle special cases (e.g., n=1)
// 4. Stay organized and don't get stuck on one approach
// 5. Think backwards if necessary