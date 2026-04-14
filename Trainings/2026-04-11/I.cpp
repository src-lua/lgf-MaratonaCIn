/**
 * Author:      Lua
 * Problem:     I
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/I
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned ll;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

ll get(
    int u, int v, 
    vector<vector<int>>&pos, 
    unordered_map<ull, ll>& memo
) {
    ull mask = (ull(u) << 32) | v;
    if (memo.count(mask)) return memo[mask];

    ll ans = 0;

    if (pos[u].size() <= pos[v].size()) {
        for (auto const &x : pos[u]) {
            ans += (
                pos[v].end() - 
                upper_bound(
                    pos[v].begin(),
                    pos[v].end(),
                    x
                )
            );
        }
    }
    else {
        for (int const &x : pos[v]) {
            ans += (
                lower_bound(
                    pos[u].begin(),
                    pos[u].end(),
                    x) - 
                    pos[u].begin()
            );
        }
    }

    return memo[mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, q; cin >> n >> k >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    ll curr = 0;
    BIT bit(k);
    vector<vector<int>> pos(k + 1);

    for (int i = 0; i < n; i++) {
        pos[arr[i]].push_back(i);
        
        curr += bit.query(k) - bit.query(arr[i]);
        bit.update(arr[i], 1);
    }

    vector<int> val(k + 1);
    iota(val.begin(), val.end(), 0);

    unordered_map<ull, ll> memo;
    memo.reserve(5e6);

    while(q--) {
        int i; cin >> i;

        int u = val[i], v = val[i + 1];

        ll total = (ll)pos[u].size() * pos[v].size();
        ll u_before_v = get(u, v, pos, memo);
        ll v_before_u = total - u_before_v;

        curr += u_before_v - v_before_u;
        swap(val[i], val[i + 1]);
        cout << curr << '\n';
    }

    return 0;
}
