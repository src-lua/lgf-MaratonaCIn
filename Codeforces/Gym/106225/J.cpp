#include <bits/stdc++.h>

using namespace std;

const int MXN = 4001;
int dp[MXN][MXN][2];

bool solve(int i, int j, int s, vector<int>& arr, vector<int>& tgt) {
    if (i == arr.size() && j == tgt.size()) return true;
    if (i >= arr.size() || j >= tgt.size()) return false;
    if (dp[i][j][s] != -1) return dp[i][j][s];

    return dp[i][j][s] = ( false
        || ((arr[i] == tgt[j] || tgt[j] == 1) && solve(i+1, j+1, 0, arr, tgt))
        || (s == 1 && solve(i+1, j+1, 1, arr, tgt))
        || (i+tgt[j]-1 < arr.size() && tgt[j] == 1 && solve(i+tgt[j]-1, j, 1, arr, tgt))
    );
}

void run() {
    int n, m; cin >> n >> m;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<int> tgt(m); for (auto &x : tgt) cin >> x;

    cout << (solve(0, 0, 0, arr, tgt) ? "YES\n" : "NO\n");

    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) 
    for (int k = 0; k <= 1; k++) dp[i][j][k] = -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof dp);
    
    int tc; cin >> tc; while(tc--) run();

    return 0;
}