#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

void count_sort(vector<int>& p, vector<int>& c) { // sorts P based on C
    int n = p.size();

    vector<int> new_p(n);
    vector<int> cnt(n);
    
    for (auto e : c) cnt[e]++; // Generate buckets size
    
    vector<int> pos(n); pos[0] = 0;
    for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
    
    for (auto e : p) {
        int idx = c[e];
        new_p[pos[idx]] = e;
        pos[idx]++;
    }
    p = new_p;
}

pair<vector<int>, vector<int>> SuffixArray(string& s) {
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        // k = 0
        vector<pair<char,int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        // k -> k + 1
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;

        count_sort(p, c); // Sorts P based on C

        vector<int> new_c(n);

        new_c[p[0]] = 0;

        for (int i = 1; i < n; i++) {

            pair<int,int> prv = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int,int> now = {c[p[i]],   c[(p[i]   + (1 << k)) % n]};

            if (now == prv) new_c[p[i]] = new_c[p[i-1]];
            else new_c[p[i]] = new_c[p[i-1]] + 1;
        }
        
        c = new_c;
        k++;
    }
    return {p, c};
}

vector<int> lcp(vector<int>& p, vector<int>& c, string& s) {
    int n = p.size();
    vector<int> l(n);

    int k = 0;
    for (int i = 0; i < n-1; i++) {
        int posi = c[i];
        int j = p[posi-1];
        
        while (s[i+k] == s[j+k]) k++;
        l[posi] = k;
        k = max(k-1, 0);
    }

    return l;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    auto [p, c] = SuffixArray(s);
    auto l = lcp(p, c, s);
    
    vector<ll> ps;

    ps.push_back(0ll);

    for (int i = 1; i < p.size(); i++){
        // p.size()-1 - p[i] - l[i];
        ps.push_back(ps.back()+p.size()-1 - p[i] - l[i]);
    }

    int q; cin >> q;

    ll x;
    for (int tc = 0; tc < q; tc++) {
        cin >> x;
        auto lb = lower_bound(ps.begin(), ps.end(), x);
        ll lo = *lb;
        int idx = lb-ps.begin();


        cout << s.substr(p[idx], s.size()-p[idx]-1-(lo-x)) << endl;
    }

    return 0;
}