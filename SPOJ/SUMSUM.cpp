/**
 * Author:      Lua
 * Problem:     SUMSUM - Enjoy Sum with Operations
 * Link:        https://www.spoj.com/problems/SUMSUM/
 * Status:      AC
 * Created:     04-02-2026 02:16:32
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "lib/data-structures/segment-tree/segment-tree.hpp"

struct Node {
    vector<int> mask;

    Node() : mask(32, 0) {}
    Node(int v) : mask(32,0) {
        for (int i = 0; i < 32; i++) mask[i] = v & (1 << i) ? 1 : 0;
    }
    
    static inline Node merge(const Node& l, const Node& r) {
        Node ans;
        for (int i = 0; i < 32; i++) ans.mask[i] = l.mask[i] + r.mask[i];
        return ans;
    }

    inline void apply(int v) {
        for (int i = 0; i < 32; i++) mask[i] = v & (1 << i) ? 1 : 0;
    }
};

const int MXN = 1e5+10;


ll choose2(ll n) {
    return (n * (n-1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for(auto &x : arr) cin >> x;

    SegTree<Node> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 1) {
            int x, i; cin >> x >> i; i--;

            seg.update(i, x);
        }

        else if (op == 2) {
            string f; cin >> f;
            int l, r; cin >> l >> r; l--, r--;

            vector<int> mask = seg.query(l, r).mask;

            if (f == "OR") {
                ll ans = 0; 
                for (int j = 0; j < 32; j++) {
                    ll c1 = mask[j];
                    ll c0 = r-l+1-c1;

                    ans += (1 << j) * (choose2(r-l+1) - choose2(c0));
                }

                cout << ans << '\n';
            }

            else if (f == "XOR") {
                ll ans = 0; 
                for (int j = 0; j < 32; j++) {
                    ll c1 = mask[j];
                    ll c0 = r-l+1-c1;

                    ans += (1 << j) * c1 * c0;
                }

                cout << ans << '\n';
            }

            else if (f == "AND") {
                ll ans = 0; 
                for (int j = 0; j < 32; j++) {
                    ll c1 = mask[j];
                    ll c0 = r-l+1-c1;

                    ans += (1 << j) * choose2(c1);
                }

                cout << ans << '\n';
            }

        }
    }
    

    return 0;
}
