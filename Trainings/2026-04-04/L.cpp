/**
 * Author:      Lua
 * Problem:     L - Looking for Taste
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101991/problem/L
 * Status:      AC
 * Created:     04-04-2026 14:08:17
 **/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) { int x; cin >> x; ans |= x; }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("looking.in", "r", stdin);

    int t; cin >> t; while(t--) solve();

    return 0;
}