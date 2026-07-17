/**
 * Author:      Lua
 * Problem:     MKTHNUM - K-th Number
 * Link:        https://www.spoj.com/problems/MKTHNUM/
 * Status:      AC
 * Created:     03-02-2026 19:26:25
 **/

#include <bits/stdc++.h>

#include "lib/data-structures/fenwick-tree/fenwick-tree.hpp"
#include "lib/data-structures/parallel-bs.hpp"

using namespace std;
using ll = long long;
using iii = tuple<int,int,int>;
using pii = pair<int,int>;

struct Node {
    ll val;
    Node(ll v = 0) : val(v) {}
    void operator+=(const Node& other) { val += other.val; }
    Node operator-(const Node& other) const {
        return Node(val - other.val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    vector<iii> queries(q);

    for (int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        queries[i] = {l, r, x};
    }

    vector<pii> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {arr[i], i}; 
    }

    sort(items.begin(), items.end());

    vector<int> decompress;
    map<int,int> compress;
    vector<vector<int>> pos;

    int id = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || items[i].first != items[i - 1].first) {
            decompress.push_back(items[i].first);
            pos.push_back({});
            id++;
        }
        
        pos.back().push_back(items[i].second);
        compress[items[i].second] = id;
    }

    int u = decompress.size();

    FenwickTree<Node> bit(n);

    auto apl = [&](int i) {
        for (auto p: pos[i]) bit.update(p, {1});
    };

    auto rlb = [&](int i) {
        for (auto p: pos[i]) bit.update(p, {-1});
    };

    auto chk = [&](int i) {
        auto [l, r, x] = queries[i];
        return bit.query(l, r).val >= x;
    };

    ParallelBS pbs(q, u);
    pbs.run(apl, rlb, chk);

    for (auto &x : pbs.ans) cout << decompress[x] << '\n';

    return 0;
}