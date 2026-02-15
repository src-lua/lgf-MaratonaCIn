/**
 * Author:      Lua
 * Problem:     J - Subsequence Sum Queries
 * Link:        https://codeforces.com/gym/101741/problem/J
 * Status:      AC
 * Created:     09-02-2026 16:46:49
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;
int mod_m;

#include "lgf-cplib/data-structures/segment-tree/segment-tree.hpp"

struct Node {
    array<ll, 20> cnt;


    Node() {
        cnt.fill(0);
        cnt[0] = 1; 
    }
    
    Node(ll v) {
        cnt.fill(0);
        cnt[0] = 1;
        cnt[v % mod_m]++; 
    }
    
    static Node merge(const Node& l, const Node& r) {
        Node res; res.cnt[0] = 0;

        for (int i = 0; i < mod_m; i++) {
            if (l.cnt[i] == 0) continue;
            for (int j = 0; j < mod_m; j++) {
                if (r.cnt[j] == 0) continue;

                int target = (i + j) % mod_m;

                ll ways = (l.cnt[i] * r.cnt[j]) % MOD;
                res.cnt[target] = (res.cnt[target] + ways) % MOD;
            }
        }
        return res;
    }

    inline void apply(long long v) {
        cnt.fill(0);
        cnt[0] = 1;
        cnt[v % mod_m]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m; mod_m = m;
    vector<int> arr(n); for (auto &x: arr) cin >> x;

    SegTree<Node> seg(arr);

    int q; cin >> q; while(q--) {
        int l, r; cin >> l >> r; l--, r--;
    
        cout << (seg.query(l, r).cnt[0]) % MOD << '\n';
    }

    return 0;
}
