/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://vjudge.net/contest/781528#problem/C
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/

#include <bits/stdc++.h>

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
                table[p][i] = min(table[p - 1][i], table[p - 1][i + (1 << (p - 1))]);
    }

    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);  // floor log
        return min(table[p][l], table[p][r - (1 << p) + 1]);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        vector<int> ps;

        int sum = 0;
        for (auto& c : s) ps.push_back(sum += (c == '(' ? 1 : -1));

        Sparse<int> sp;
        sp.build(ps);

        function<pair<ll, int>(int, int)> solve = [&](int L, int R) {
            // cout << L << " " << R << endl;
            if (R <= L) return pair<ll, int>(0ll, 1);

            int h = 1;
            ll ans = 0;
            int mn = sp.query(L, R);

            for (; R - L >= 1;) {
                int l = L, r = R, mid, br = R;
                while (l <= r) {
                    mid = (l + r) / 2;
                    if (sp.query(L, mid) == mn)
                        br = mid, r = mid - 1;
                    else
                        l = mid + 1;
                }

                auto [cd, hc] = solve(L + 1, br - 1);

                ll w = br - L;
                ans += w * hc;
                // cout << L << " " << br << " -- " << mn << " " << hc << " | " << w*hc << " " << cd << endl;

                ans -= cd;
                h = max(h, hc);
                L = br + 1;
            }

            // cout << ans << "_" << h << endl;
            return pair<ll, int>(ans, h + 1);
        };

        cout << solve(0, s.size() - 1).first << "\n";
    }

    return 0;
}