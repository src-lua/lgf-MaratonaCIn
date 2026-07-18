#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n; cin >> n;
    vector<ll> arr(n);
    vector<ll> prefix(n+1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i%2 == 0) arr[i] = -arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }

    sort(prefix.begin(), prefix.end());

    for (int i = 0; i < n; i++) {
        if (prefix[i] == prefix[i+1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;

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