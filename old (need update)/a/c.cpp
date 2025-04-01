#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> p(n+1);
    p[0] = 0;

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[i+1]) p[i+1] = p[i] + 1;
        else p[i+1] = 0;

        if (p[i+1] >= 2) s.insert(i+2);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int lb = *(s.lower_bound(l));
        ifç (p[lb-1] -p[l] < 2) lb = *(++s.lower_bound(l));
        cout << min(lb-l, r-l+1) << endl;

    }

    return 0;
}