#include <bits/stdc++.h>

using namespace std;

void radix_sort(vector<pair<pair<int,int>,int>>& arr) {
    int n = arr.size();
    vector<pair<pair<int,int>,int>> new_arr(n);
    {
        vector<int> cnt(n);
        
        for (auto e : arr) cnt[e.first.second]++; // Generate buckets size
        vector<int> pos(n); pos[0] = 0;
        for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
        
        for (auto e : arr) {
            int idx = e.first.second;
            new_arr[pos[idx]] = e;
            pos[idx]++;
        }
    }
    {
        vector<int> cnt(n);
        
        for (auto e : new_arr) cnt[e.first.first]++; // Generate buckets size
        vector<int> pos(n); pos[0] = 0;
        for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1]; // Generate buckets index
                
        for (auto e : new_arr) {
            int idx = e.first.first;
            arr[pos[idx]] = e;
            pos[idx]++;
        }
    }
}

vector<int> SuffixArray(string s) {
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
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }
    return p;
}

int main() {
    string s; cin >> s;
    for (auto e : SuffixArray(s)) {
        cout << e << " ";
    } cout << endl;
    return 0;
}