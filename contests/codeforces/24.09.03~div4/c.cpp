#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int x, y, k; cin >> x >> y >> k;

    int a = (x+(k-1)) / k;
    int b = (y+(k-1)) / k;

    if (b >= a) {
        cout << b*2 << endl;
    }
    else {
        cout << (a*2) - 1 << endl;
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