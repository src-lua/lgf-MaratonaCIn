#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int k = 0;

int solve() {
    vector<double> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    
    
    if (v[0] <= 56 && v[1] <= 45 && v[2] <= 25 && v[3] <= 7) {
        cout << 1 << endl;
        k++;
    } else if (v[0] + v[1] + v[2] <= 125 && v[3] <= 7) {
        cout << 1 << endl;
        k++;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    cout << k << endl;

    return 0;
}