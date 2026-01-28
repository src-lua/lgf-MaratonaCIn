/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/781528#problem/A
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int x = stoi(a), y = stoi(b);

    string ans = to_string(x + y);
    reverse(ans.begin(), ans.end());

    cout << stoi(ans) << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}