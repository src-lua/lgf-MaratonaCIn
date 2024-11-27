#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n; cin >> n;

    ll sum = 0;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    ll answ = sqrt(sum);

    if (answ * answ == sum) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    

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