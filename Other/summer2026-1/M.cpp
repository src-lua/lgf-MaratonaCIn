/**
 * Author:      Lua
 * Problem:     M
 * Link:        https://vjudge.net/contest/781528#problem/M
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

template <typename T>
struct Sparse {
    vector<vector<T>> table;

    void build(vector<T>& v) {
        int N = v.size(), MLOG = 32 - __builtin_clz(N);
        table.assign(MLOG, v);

        for (int p = 1; p < MLOG; p++)
            for (int i = 0; i + (1 << p) <= N; i++)
                table[p][i] = gcd(table[p - 1][i], table[p - 1][i + (1 << (p - 1))]);
    }

    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);  // floor log
        return gcd(table[p][l], table[p][r - (1 << p) + 1]);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> sla(n);
    for (auto& x : sla) cin >> x;

    Sparse<int> sp;
    sp.build(sla);
    map<int, ll> ans;

    for (int L = 0, R; L < n; L++) {
        R = L;

        while (R < n) {
            int gc = sp.query(L, R);
            // cout << L << " " << R << " bla\n";cout.flush();

            int l = R, r = n - 1, m, mx = R;
            while (l <= r) {
                m = (l + r) / 2;
                if (sp.query(L, m) == gc)
                    mx = m, l = m + 1;
                else
                    r = m - 1;
            }

            ans[gc] += mx - R + 1;
            R = mx + 1;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }

    return 0;
}