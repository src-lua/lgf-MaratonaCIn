/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/D
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;
using ld = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(10) << fixed;

    vector<int> r(3); for (auto &x : r) cin >> x;
    int n, q; cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int c1, l1, c2, l2; 
        cin >> c1 >> l1 >> c2 >> l2; 
        c1--, c2--; l1--, l2--;

        if (c1 > c2) swap(c1, c2), swap(l1, l2);
    
        auto get = [&](int c){
            ld ans = abs(r[c1] - r[c]) + abs(r[c2] - r[c]);
            ans += (acos(-1) * 2 * r[c]) * min(abs(l1-l2), n - abs(l1-l2)) / n;
            return ans;
        };

        cout << min({get(0), get(1), get(2)}) << '\n';
    }
    

    return 0;
}
