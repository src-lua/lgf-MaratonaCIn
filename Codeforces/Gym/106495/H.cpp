/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/gym/106495/problem/H
 * Status:      AC
 * Created:     10-07-2026 08:10:03
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
vector<int> manacher(const T& s) {
    int l = 0, r = -1, n = s.size();
    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) k++;
        d1[i] = k--;
        if (i + k > r) l = i -k, r = i + k;
    }
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
        k++;
        while(i+k <=n && i-k >= 0 && s[i+k-1]==s[i-k]) k++;
        d2[i] = --k;
        if (i + k - 1 > r) l = i-k,r=i+k-1;
    }
    vector<int> ret(2*n-1);
    for (int i = 0; i < n; i++) ret[2*i] = 2 * d1[i] -1;
    for (int i = 0; i < n - 1; i ++) ret[2*i+1] = 2*d2[i+1];
    return ret;
}

void solve() {
    string s, t; cin >> s >> t;
    auto arr_s = manacher(s), arr_t = manacher(t);
    
    int n = s.size(), m = 0;
    while (m < n && s[m] == t[n - 1 - m] && t[m] == s[n - 1 - m]) m++;

    ll ans = m;

    for (int i = 0; i < 2 * n - 1; i++) {
        int len = min(arr_s[i], arr_t[i]);
        if (len == 0) continue;

        int mx = i / 2;
        int mn = (i - len + 1) / 2;

        int start = max(1, mn);
        int end = min(m, mx);

        if (start <= end) ans += (end - start + 1);
    }

    string rev_s = s, rev_t = t;
    reverse(rev_s.begin(), rev_s.end());
    reverse(rev_t.begin(), rev_t.end());
    
    auto rev_arr_s = manacher(rev_s), rev_arr_t = manacher(rev_t);

    for (int i = 0; i < 2 * n - 1; i++) {
        int len = min(rev_arr_s[i], rev_arr_t[i]);
        if (len == 0) continue;

        int mx = i / 2;
        int mn = (i - len + 1) / 2;

        int start = max(1, mn);
        int end = min(m, mx);

        if (start <= end) ans += (end - start + 1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
