#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

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

int lowerBound(int l, int r, vector<int>& p, string& s, string& t) {
    int answ = r+1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        string substring = s.substr(p[m], t.size());

        if (substring < t) 
            l = m + 1;
        else {
            r = m - 1;
            answ = m;
        }
    }
    return answ;
}

int upperBound(int l, int r, vector<int>& p, string& s, string& t) {
    int answ = r+1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        string substring = s.substr(p[m], t.size());

        if (substring <= t) 
            l = m + 1;
        else {
            r = m - 1;
            answ = m;
        }
    }
    return answ;
}

int get_substrings(string& s, string& t, vector<int>& p) {
    int l = lowerBound(0, p.size()-1, p, s, t);
    int u = upperBound(0, p.size()-1, p, s, t);

    if (l < p.size() && s.substr(p[l], t.size()) == t) return u - l; 
    return 0;
}

string lcs(vector<int>& p, vector<int>& l, string & st, int m) { // m = s.size()
    int mx = 0;
    string lcs = "";
    for (int i = 1; i < l.size(); i++) {
        int i_group = (0 <= p[i] && p[i] < m), j_group = (0 <= p[i - 1] && p[i - 1] < m);
        if (i_group != j_group) {
            if (mx < l[i]) {
                mx = l[i];
                lcs = st.substr(p[i], mx);
            }
        }
    }
    return lcs;
}

int main() {
    string s; cin >> s;
    string t; cin >> t;

    string st = s + '+' + t;

    auto [p, c] = SuffixArray(st);
    auto l = lcp(p, c, st);
    
    // cout << lcs(p, l, st, s.size());
    
    // for (size_t i = 0; i < p.size(); i++) {
    //         cout << l[i] << ' ' << p[i] << ' ' << st.substr(p[i], p.size()-1) << endl;
    //     }
        
    // for (size_t i = 0; i < p.size(); i++) cout << p[i] << ' ';
    // cout << endl;
    // for (size_t i = 1; i < p.size(); i++) cout << l[i] << ' ';


    // int tc; cin >> tc;
    // string t;
    // for (int i = 0; i < tc; i++) {
    //     cin >> t;

    //     if (get_substrings(s, t, p) > 0) cout << "Yes\n";
    //     else cout << "No\n";
    // }

    return 0;
}