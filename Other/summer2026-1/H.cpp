/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://vjudge.net/contest/781528#problem/H
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 3;

vector<int> seg[4 * MAXN];

void build(int no, int l, int r) {
    if (l == r) {
        sort(begin(seg[no]), end(seg[no]));
        return;
    }

    int m = (l + r) / 2, e = no * 2, d = e + 1;

    build(e, l, m);
    build(d, m + 1, r);

    int i = 0, j = 0;
    while (i < seg[e].size() && j < seg[d].size()) seg[no].push_back(seg[e][i] < seg[d][j] ? seg[e][i++] : seg[d][j++]);

    while (i < seg[e].size()) seg[no].push_back(seg[e][i++]);
    while (j < seg[d].size()) seg[no].push_back(seg[d][j++]);
}

void update(int no, int l, int r, int pos, int x) {
    if (pos < l || r < pos) return;
    if (l == r) {
        seg[no].push_back(x);
        return;
    }

    int m = (l + r) / 2, e = no * 2, d = e + 1;

    update(e, l, m, pos, x);
    update(d, m + 1, r, pos, x);
}

int query(int no, int l, int r, int a, int b, int x) {
    if (b < l || r < a || seg[no].empty()) return 0;
    if (a <= l && r <= b) {
        auto it = lower_bound(begin(seg[no]), end(seg[no]), x);
        return end(seg[no]) - it;
    }

    int m = (l + r) / 2, e = no * 2, d = e + 1;

    return query(e, l, m, a, b, x) + query(d, m + 1, r, a, b, x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        update(1, 1, 1e6, l, r);
    }

    build(1, 1, 1e6);

    while (q--) {
        int m;
        cin >> m;

        int lst = 0;
        int ans = 0;

        vector<int> pts(m);
        for (auto& x : pts) cin >> x;
        sort(begin(pts), end(pts));

        for (auto p : pts) {
            ans += query(1, 1, 1e6, lst + 1, p, p);
            lst = p;
        }

        cout << ans << endl;
    }
}