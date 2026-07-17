/**
 * Author:      Lua
 * Problem:     METEORS
 * Link:        https://www.spoj.com/problems/METEORS/
 * Status:      ~
 * Created:     17-07-2026 08:58:22
 **/

#include <bits/stdc++.h>

#include "lib/data-structures/segment-tree/lazy-segment-tree.hpp"

using namespace std;
using ll = long long;
using iii = tuple<int,int,int>;

struct Tag {
    ll add = 0;
    void compose(const Tag& t) {
        add += t.add;
    }
};

struct Node {
    ll val = 0;
    Node(ll v = 0) : val(v) {}
    static Node merge(const Node& l, const Node& r) {
        return Node(l.val + r.val);
    }
    void apply(const Tag& t, int l, int r) {
        val += t.add * (r - l + 1);
    }
};

struct Ctx {
    int m, q;
    vector<iii>& rains;
    vector<vector<int>>& sectors;
    vector<int>& intent;
    vector<int>& ans;
    LazySegmentTree<Node, Tag>& seg;

    void apply_rain(int idx, int sign) {
        if (idx >= q) return;
        auto [l, r, x] = rains[idx];
        ll val = (ll)x * sign;
        
        if (l <= r) {
            seg.update(l, r, {val});
        }
        else {
            seg.update(l, m - 1, {val});
            seg.update(0, r, {val});
        }
    }
};

vector<int> test(int l, int r, vector<int>& actives, Ctx& ctx) {
    for (int i = l; i <= r; i++) {
        ctx.apply_rain(i, 1);
    }

    vector<int> passed;

    for (auto &idx : actives) {
        ll val = 0;
        for (auto &x : ctx.sectors[idx]) {
            val += ctx.seg.query(x, x).val;
            if (val >= ctx.intent[idx]) break;
        }
        if (val >= ctx.intent[idx]) {
            passed.push_back(idx);
        }
    }

    return passed;
}

void parallel_bs(int l, int r, vector<int>& actives, Ctx& ctx) {
    if (actives.empty()) return;

    if (l == r) {
        vector<int> pass = test(l, l, actives, ctx);
        for (auto &x : pass) ctx.ans[x] = l;
        ctx.apply_rain(l, -1);
        return;
    }

    int mid = l + (r - l) / 2;
    
    vector<int> pass = test(l, mid, actives, ctx);
    
    int a_sz = actives.size(), p_sz = pass.size();
    vector<int> not_pass; not_pass.reserve(a_sz - p_sz);

    int i = 0, j = 0;
    while (i < a_sz && j < p_sz) {
        if (actives[i] == pass[j]) i++, j++;
        else {
            not_pass.push_back(actives[i]);
            i++;
        }
    }
    while (i < a_sz) {
        not_pass.push_back(actives[i]);
        i++;
    }

    parallel_bs(mid + 1, r, not_pass, ctx);

    for (int idx = l; idx <= mid; idx++) ctx.apply_rain(idx, -1);
    parallel_bs(l, mid, pass, ctx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> owner(m); for(auto &x : owner) cin >> x;
    vector<int> intent(n); for(auto &x: intent) cin >> x;
    
    vector<vector<int>> sectors(n); 
    for (int i = 0; i < m; i++) sectors[owner[i]-1].push_back(i);
    
    int q; cin >> q; vector<iii> rains(q);
    for (int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        rains[i] = {l, r, x};
    }

    vector<int> ans(n, -1);

    LazySegmentTree<Node, Tag> seg(m);

    Ctx ctx{m, q, rains, sectors, intent, ans, seg};

    vector<int> countries(n); 
    iota(countries.begin(), countries.end(), 0);
    
    parallel_bs(0, q, countries, ctx);

    for (auto &x : ans) 
        cout << (x != -1 ? to_string(x+1) : "NIE") << '\n';

    return 0;
}
