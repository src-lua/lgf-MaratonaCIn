#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n; cin >> n;

    int x, y;
    int maxzero = 0, maxone = 0;

    unordered_set<int> zero, one;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        
        

        if (y == 0) {zero.insert(x); maxzero = max(x, maxzero); }
        else {one.insert(x); maxone = max(x, maxone); }
    }

    ll answ = 0;

    for (auto e : zero) {
        if (one.count(e) != 0) answ += zero.size()-1 + one.size()-1;

        if (one.count(e-1) && one.count(e+1)) answ++;
    }

    for (auto e : one) {
        if (zero.count(e-1) && zero.count(e+1)) answ++;
    }
    
    cout << answ << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}