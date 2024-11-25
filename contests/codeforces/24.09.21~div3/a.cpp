#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, k; cin >> n >> k;

    int c = 0;

    int answ = 0;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (x >= k) c += x; else
        if (x == 0 && c) {answ++; c--;}

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