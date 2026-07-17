/**
 * Author:      Lua
 * Problem:     METEORS
 * Link:        https://www.spoj.com/problems/METEORS/
 * Status:      ~
 * Created:     17-07-2026 08:58:22
 **/

#include <bits/stdc++.h>

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

template <typename NODE, typename TAG>
struct LazySegmentTree {
  int N;
  vector<NODE> seg;
  vector<TAG> lazy;

  explicit LazySegmentTree(int n)
      : N(n), seg(4 * n), lazy(4 * n) {}

  template <typename T>
  LazySegmentTree(const vector<T> &v)
      : LazySegmentTree((int)v.size()) {
    build(1, 0, N - 1, v);
  }

  template <typename T>
  void build(int no, int l, int r, const vector<T> &v) {
    if (l == r) {
      seg[no] = NODE(v[l]);
      return;
    }
    int m = (l + r) >> 1;
    build(no << 1, l, m, v);
    build((no << 1) | 1, m + 1, r, v);
    seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
  }

  void push(int no, int lo, int hi) {
    int m = (lo + hi) >> 1;
    int l = no << 1, r = l | 1;

    seg[l].apply(lazy[no], lo, m);
    lazy[l].compose(lazy[no]);

    seg[r].apply(lazy[no], m + 1, hi);
    lazy[r].compose(lazy[no]);

    lazy[no] = TAG();
  }

  void update(int no, int l, int r, int a, int b, const TAG &v) {
    if (b < l || r < a) return;
    if (a <= l && r <= b) {
      seg[no].apply(v, l, r);
      lazy[no].compose(v);
      return;
    }
    push(no, l, r);
    int m = (l + r) >> 1;
    update(no << 1, l, m, a, b, v);
    update((no << 1) | 1, m + 1, r, a, b, v);
    seg[no] = NODE::merge(seg[no << 1], seg[(no << 1) | 1]);
  }

  NODE query(int no, int l, int r, int a, int b) {
    if (b < l || r < a) return NODE();
    if (a <= l && r <= b) return seg[no];
    push(no, l, r);
    int m = (l + r) >> 1;
    return NODE::merge(query(no << 1, l, m, a, b),
                       query((no << 1) | 1, m + 1, r, a, b));
  }

  void update(int l, int r, const TAG &v) {
    update(1, 0, N - 1, l, r, v);
  }
  NODE query(int l, int r) { return query(1, 0, N - 1, l, r); }
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

template <typename Test, typename Apply, typename Back> 
void parallel_bs(int l, int r, vector<int>& actives, vector<int>& ans, Test test, Apply apply, Back back) {
    if (actives.empty()) return;

    apply(l,r);

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

    back(l, m);
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
