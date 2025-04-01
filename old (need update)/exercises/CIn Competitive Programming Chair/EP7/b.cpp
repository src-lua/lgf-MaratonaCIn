#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n; cin >> n;
    vector<int> arr(n);
    ll zeros = 0, ones = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) zeros++;
        if (arr[i] == 1) ones++;
    }

    cout << (1ll << zeros) * ones << endl;

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