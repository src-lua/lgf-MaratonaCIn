/**
 * Author:      Lua
 * Problem:     L - Eyb0ss
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/L
 * Status:      ~
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

void solve(){
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (auto &row : board) for (auto &x: row) cin >> x;

    SparseTable2D<NodeMinMax> st(board);

    ll ans = 0;

    for (int r1 =  0; r1 < n; r1++) for (int c1 =  0; c1 < n; c1++) 
    for (int r2 = r1; r2 < n; r2++) for (int c2 = c1; c2 < n; c2++) 
        ans += st.query(r1, c1, r2, c2).mx - st.query(r1, c1, r2, c2).mn;
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
