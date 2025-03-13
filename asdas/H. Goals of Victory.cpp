#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;
    long long sum = 0;

    int x;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        sum += x;
    }

    cout << -sum << endl;
    

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