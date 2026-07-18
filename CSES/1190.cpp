    /**
     * Author:      Lua
     * Problem:     1190 - Subarray Sum Queries
     * Link:        https://cses.fi/problemset/task/1190
     * Status:      AC
     * Created:     06-02-2026 01:02:47
     **/

    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;

    #include "lib/data-structures/segment-tree/segment-tree.hpp"

    struct Node {
        ll ans, pre, suf, sum;

        Node(int v = 0) : ans(max(0,v)), pre(max(0,v)), suf(max(0,v)), sum(v) {}

        static inline Node merge(const Node& l, const Node& r) {
            Node ans;
            ans.sum = l.sum + r.sum;
            ans.pre = max(l.pre, l.sum+r.pre);
            ans.suf = max(r.suf, l.suf+r.sum);
            ans.ans = max({l.ans, r.ans, l.suf+r.pre});
            return ans;
        }

        inline void apply(int v) {
            sum = v, ans = pre = suf = max(0, v);
        }
    };

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        int n, q; cin >> n >> q;
        vector<int> arr(n); for (auto &x : arr) cin >> x;

        SegTree<Node> seg(arr);

        for (int i = 0; i < q; i++) {
            int idx, x; cin >> idx >> x; idx--;

            seg.update(idx, x);
            cout << seg.query(0, n-1).ans << '\n';
        }

        return 0;
    }
