/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/gym/106225/problem/L
 * Status:      ~
 * Created:     16-07-2026 13:08:05
 **/

#include <bits/stdc++.h>

using namespace std;

struct SuffixArray {
  string s;
  vector<int> sa, rk, lcp;

  SuffixArray() {}

  SuffixArray(string s) : s(s) {
    build();
    build_lcp();
  }

  void build() {
    s += '$';
    int n = s.size();
    sa.resize(n);
    rk.resize(n);

    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) sa[i] = a[i].second;
    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      int inc = a[i].first != a[i - 1].first;
      rk[sa[i]] = rk[sa[i - 1]] + inc;
    }

    for (int k = 0; (1 << k) < n; k++) {
      for (int i = 0; i < n; i++)
        sa[i] = (sa[i] - (1 << k) + n) % n;
      count_sort();
      vector<int> new_rk(n);
      new_rk[sa[0]] = 0;
      auto snd = [&](int x) { return rk[(x + (1 << k)) % n]; };
      for (int i = 1; i < n; i++) {
        pair<int, int> prev = {rk[sa[i - 1]], snd(sa[i - 1])};
        pair<int, int> now = {rk[sa[i]], snd(sa[i])};
        new_rk[sa[i]] = new_rk[sa[i - 1]] + (now != prev);
      }
      rk = new_rk;
    }
  }

  void count_sort() {
    int n = sa.size();
    vector<int> new_sa(n), cnt(n, 0), pos(n, 0);
    for (auto e : rk) cnt[e]++;
    for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto e : sa) new_sa[pos[rk[e]]++] = e;
    sa = new_sa;
  }

  void build_lcp() {
    int n = sa.size();
    lcp.assign(n, 0);
    for (int i = 0, h = 0; i < n; i++) {
      if (rk[i] == 0) {
        h = 0;
        continue;
      }
      int j = sa[rk[i] - 1];
      while (s[i + h] == s[j + h]) h++;
      lcp[rk[i]] = h;
      if (h) h--;
    }
  }
};

struct NodeMin {
    int val, pos;
    NodeMin(int v = 2e9, int p = -1) : val(v), pos(p) {}

    static NodeMin merge(const NodeMin& l, const NodeMin& r) {
        return l.val <= r.val ? l : r;
    }
};

struct NodeMax {
    int val, pos;
    NodeMax(int v = -2e9, int p = -1) : val(v), pos(p) {}

    static NodeMax merge(const NodeMax& l, const NodeMax& r) {
        return l.val <= r.val ? r : l;
    }
};

template <typename NODE>
struct SparseTable {
  int N, K;
  vector<vector<NODE>> st;
  vector<int> lg;

  SparseTable() {}

  template <typename T>
  SparseTable(const vector<T> &v) : N(v.size()) {
    K = (N > 0) ? __lg(N) : 0;
    st.assign(K + 1, vector<NODE>(N));
    lg.assign(N + 1, 0);
    for (int i = 2; i <= N; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < N; i++) st[0][i] = NODE(v[i]);
    for (int j = 1; j <= K; j++)
      for (int i = 0; i + (1 << j) <= N; i++)
        st[j][i] = NODE::merge(st[j - 1][i],
                               st[j - 1][i + (1 << (j - 1))]);
  }

  NODE query(int l, int r) {
    int j = lg[r - l + 1];
    return NODE::merge(st[j][l], st[j][r - (1 << j) + 1]);
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<vector<int>> pos(26);
    vector<vector<int>> freq(26, vector<int>(n+1));

    for (int i = 0; i < n; i++) {
        pos[s[i]-'a'].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            freq[j][i] = freq[j][i-1] + ((s[i-1]-'a')==j);
        }
    }

    SuffixArray sa(s);
    SparseTable<NodeMin> st(sa.lcp);

    vector<SparseTable<NodeMin>> mns(26);
    vector<SparseTable<NodeMax>> mxs(26);

    for (int i = 0; i < 26; i++) {
        if(pos[i].empty())continue;
        vector<int> aux(pos[i].size());
        for (int j = 0; j < pos[i].size(); j++) {
            aux[j] = sa.rk[pos[i][j]];
        }
        mns[i] = SparseTable<NodeMin>(aux);
        mxs[i] = SparseTable<NodeMax>(aux);
    }

    while(q--) {
        int l, r; 
        cin>>l>>r;
        l--, r--;
        int ans = 0;
        vector<int> cand;
        int mf = 0;
        for(int i = 0; i < 26; i++){
            int fr = freq[i][r+1] - freq[i][l];
            mf = max(mf, fr);
        }
        for(int i = 0; i < 26; i++){
            int fr = freq[i][r+1] - freq[i][l];
            if(fr == mf)cand.push_back(i);
        }
        if(mf == 1){
            ans= r-l+1;
        } else{
            for (auto i : cand) {
                if(pos[i].empty())continue;
                
                int lb = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
                int ub = upper_bound(pos[i].begin(), pos[i].end(), r) - pos[i].begin();

                if(lb >= pos[i].size()) continue;
                if(ub < 0)continue;
                if(lb >= ub) continue;
                
                int mn = mns[i].query(lb, ub-1).val;
                int mx = mxs[i].query(lb, ub-1).val;
                
                //ans = max(ans, st.query(mn+1, mx).val);
                ans = max(ans, min(st.query(mn+1, mx).val, r-pos[i][ub-1]+1));
            }  
        }
    
        cout << ans << endl;
    }

    return 0;
}