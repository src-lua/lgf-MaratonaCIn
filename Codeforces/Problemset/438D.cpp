/**
 * Author:      Lua
 * Problem:     D - The Child and Sequence
 * Link:        https://codeforces.com/problemset/problem/438/D
 * Status:      AC
 * Created:     06-02-2026 00:03:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include "lgf-cplib/data-structures/segment-tree/seg-beats.hpp"

const ll NO_OP = 1e18; 

struct Tag {
    ll set, mod;

    Tag(ll set = NO_OP, ll mod = NO_OP) : set(set), mod(mod) {}

    void inline compose(const Tag& t) {
        if (set != NO_OP) {
            if (t.set != NO_OP) set = t.set, mod = NO_OP;
            else set %= t.mod;
        }
        else {
            if (t.set != NO_OP) set = t.set, mod = NO_OP;
            else if (mod == NO_OP) mod = t.mod;
            // CASO BEATS, não dá pra compor 
            // if (mod != NO_OP && t.mod != NO_OP) 
        }
    }
};

struct Node {
    ll val;
    ll mx, mn;

    Node(ll val = 0) : val(val), mx(val), mn(val) {}

    inline static Node merge(const Node& l, const Node& r) {
        Node ans;
        ans.val = l.val + r.val;
        ans.mx = max(l.mx, r.mx);
        ans.mn = min(l.mn, r.mn);
        return ans;
    }

    inline void apply(const Tag& t, ll l, ll r) {
        if (t.set != NO_OP) {
            mx = mn = t.set;
            val = t.set * (r-l+1);
        }
        else if (t.mod != NO_OP) {
            mx %= t.mod;
            mn %= t.mod;
            val = mx * (r-l+1);
        }
    }

    inline bool break_condition(const Tag& t) const {
        return t.set == NO_OP && mx < t.mod;
    }

    inline bool tag_condition(const Tag& t) const {
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    
    vector<Node> arr; arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.emplace_back(x);
    }

    SegBeats<Node, Tag> seg(arr);
    
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        
        if (op == 1) {
            int l, r; cin >> l >> r; l--, r--;
            
            cout << seg.query(l, r).val << '\n';
        }
        
        else if (op == 2) {
            int l, r, x; cin >> l >> r >> x; l--, r--;

            seg.update(l, r, {NO_OP, x});
        }

        else if (op == 3) {
            int idx, x; cin >> idx >> x; idx--;

            seg.update(idx, idx, {x, NO_OP});
        }
    }
    

    return 0;
}
