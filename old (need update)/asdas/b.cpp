#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    int x;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) ones++;
        else twos++;
    }

    if (ones % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        if (ones >= 2) cout << "YES" << endl;
        else if (twos % 2 == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    

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