/**
 * Author:      Lua
 * Problem:     MKTHNUM - K-th Number
 * Link:        https://www.spoj.com/problems/MKTHNUM/
 * Status:      AC
 * Created:     03-02-2026 19:26:25
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

#include "lgf-cplib/data-structures/segment-tree/dynamic-persistent-segment-tree.hpp"

struct Node {
    int count;
    Node(int v = 0) : count(v) {}

    static Node neutral() { return Node(0); }

    static Node merge(const Node& l, const Node& r) { return Node(l.count + r.count); }
};

const int MXN = 2e9+10;
const int OFFSET = 1e9+5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    PersistentSegmentTree<Node> seg(MXN);

    for (auto x : arr) seg.update(x+OFFSET, Node(1));

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;

        auto less_than = [&](ll x) { 
            // x += OFFSET; x = clamp(x, 0LL, ll(MXN));
            x += OFFSET; x = max(0LL, x), x = min(x, ll(MXN-1));
            return seg.query(r + 1, 0, x).count - seg.query(l, 0, x).count; 
        };

        int low = -1e9, high = 1e9;
        int ans = 1e9;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (less_than(mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}