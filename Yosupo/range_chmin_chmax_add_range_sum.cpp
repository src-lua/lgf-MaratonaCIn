/**
 * Author:      Lua
 * Problem:     range_chmin_chmax_add_range_sum - Range Chmin Chmax Add Range Sum
 * Link:        https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
 * Status:      AC
 * Created:     05-02-2026 22:22:44
 **/

#include <bits/stdc++.h>

#include "lgf-cplib/data-structures/segment-tree/seg-beats.hpp"

using ll = long long;
const ll INF = 1e18;

struct Tag {
    ll add = 0, set_min = INF, set_max = -INF;

    void inline compose(const Tag& t) {
        if (set_min != INF) set_min += t.add;
        if (set_max != -INF) set_max += t.add;
        add += t.add;

        if (t.set_min != INF) {
            set_min = (set_min == INF ? t.set_min : min(set_min, t.set_min));

            if (set_max != -INF) {
                set_max = min(set_max, t.set_min);
            }
        }

        if (t.set_max != -INF) {
            set_max = (set_max == -INF ? t.set_max : max(set_max, t.set_max));
        }
    }
};

struct Node {
    ll sum = 0, mn = INF, mx = -INF, mn2 = INF, mx2 = -INF;
    int cnt_mn = 0, cnt_mx = 0;

    Node(ll v = 0) : sum(v), mn(v), mx(v), mn2(INF), mx2(-INF), cnt_mn(1), cnt_mx(1) {}

    static inline Node merge(const Node& l, const Node& r) {
        Node res;
        res.sum = l.sum + r.sum;
        res.mn = min(l.mn, r.mn);
        res.mx = max(l.mx, r.mx);

        res.cnt_mn = (l.mn == res.mn ? l.cnt_mn : 0) + (r.mn == res.mn ? r.cnt_mn : 0);
        res.cnt_mx = (l.mx == res.mx ? l.cnt_mx : 0) + (r.mx == res.mx ? r.cnt_mx : 0);

        res.mn2 = INF;
        if (l.mn != res.mn) res.mn2 = min(res.mn2, l.mn);
        if (l.mn2 != INF)   res.mn2 = min(res.mn2, l.mn2);
        if (r.mn != res.mn) res.mn2 = min(res.mn2, r.mn);
        if (r.mn2 != INF)   res.mn2 = min(res.mn2, r.mn2);

        res.mx2 = -INF;
        if (l.mx != res.mx) res.mx2 = max(res.mx2, l.mx);
        if (l.mx2 != -INF)  res.mx2 = max(res.mx2, l.mx2);
        if (r.mx != res.mx) res.mx2 = max(res.mx2, r.mx);
        if (r.mx2 != -INF)  res.mx2 = max(res.mx2, r.mx2);

        return res;
    }

    void inline apply(const Tag& t, int l, int r) {
        if (t.add != 0) {
            sum += (ll)t.add * (r - l + 1);
            mn += t.add;
            mx += t.add;
            if (mn2 != INF) mn2 += t.add;
            if (mx2 != -INF) mx2 += t.add;
        }

        if (t.set_min != INF && mx > t.set_min) {
            if (mn >= t.set_min) {
                sum = (ll)(r - l + 1) * t.set_min;
                mn = mx = t.set_min;
                cnt_mn = cnt_mx = r - l + 1;
                mn2 = INF;
                mx2 = -INF;
            } 
            else {
                sum -= (ll)cnt_mx * (mx - t.set_min);
                if (mn2 == mx) mn2 = t.set_min;
                mx = t.set_min;
                if (mn == mx) {
                    cnt_mn = cnt_mx = r - l + 1;
                    mn2 = INF;
                    mx2 = -INF;
                }
            }
        }

        if (t.set_max != -INF && mn < t.set_max) {
            if (mx <= t.set_max) {
                sum = (ll)(r - l + 1) * t.set_max;
                mn = mx = t.set_max;
                cnt_mn = cnt_mx = r - l + 1;
                mn2 = INF;
                mx2 = -INF;
            }
            else {
                sum += (ll)cnt_mn * (t.set_max - mn);
                if (mx2 == mn) mx2 = t.set_max;
                mn = t.set_max;
                if (mn == mx) {
                    cnt_mn = cnt_mx = r - l + 1;
                    mn2 = INF;
                    mx2 = -INF;
                }
            }
        }
    }

    bool inline break_condition(const Tag& t) const {
        return t.add == 0 &&
               (t.set_min == INF || t.set_min >= mx) &&
               (t.set_max == -INF || t.set_max <= mn);
    }

    bool inline tag_condition(const Tag& t) const {
        ll new_mn = mn + t.add;
        ll new_mx = mx + t.add;
        ll new_mn2 = (mn2 == INF ? INF : mn2 + t.add);
        ll new_mx2 = (mx2 == -INF ? -INF : mx2 + t.add);

        return (t.set_min == INF || new_mx <= t.set_min || new_mx2 < t.set_min) &&
               (t.set_max == -INF || new_mn >= t.set_max || new_mn2 > t.set_max);
    }
};

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<Node> arr;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr.emplace_back(x);
    }
    
    SegBeats<Node, Tag> seg(arr);

    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        int l, r; cin >> l >> r; r--;
    
        if (op == 0) { // update min
            ll x; cin >> x;

            seg.update(l, r, {0, x, -INF});
        }
        
        else if (op == 1) { // update max
            ll x; cin >> x;
            
            seg.update(l, r, {0, INF, x});
        }
        
        else if (op == 2) { // update sum
            ll x; cin >> x;
            
            seg.update(l, r, {x, INF, -INF});
        }
        
        else if (op == 3) { // query sum    
            cout << seg.query(l, r).sum << '\n';
        }
    }

    return 0;
}
