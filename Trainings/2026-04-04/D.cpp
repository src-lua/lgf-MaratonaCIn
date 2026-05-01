/**
 * Author:      Lua
 * Problem:     D - Dull Chocolates
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101991/problem/D
 * Status:      AC
 * Created:     04-04-2026 14:08:17
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

void xor_set(set<int>& a, set<int>& b) {
    for (int y : b) {
        auto it = a.find(y);
        if (it != a.end()) a.erase(it);
        else a.insert(y);
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pii> arr(k);
    for (auto &[x, y] : arr) cin >> x >> y;

    set<int> rows, cols;

    for (auto const& [x, y] : arr) rows.insert(x);

    vector<set<int>> board(rows.size());

    map<int,int> compress_row;
    {int i = 0; for (int r : rows) compress_row[r] = i++;}

    for (auto &[x, y] : arr)
        board[compress_row[x]].insert(y);

    vector<int> rows_v(rows.begin(), rows.end());
    rows_v.push_back(n + 1);

    set<int> curr = {m + 1};

    ll ans = 0;

    for (int i = 0; i < (int)rows.size(); i++) {
        xor_set(curr, board[i]);

        ll answ = 0;

        auto it = curr.begin();
        while (it != curr.end()) {
            int a = *it++;
            if (it == curr.end()) break;
            int b = *it++;
            answ += b - a;
        }

        ans += answ * (rows_v[i+1] - rows_v[i]);
    }

    cout << ans << ' ' << (ll)n*m - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}
