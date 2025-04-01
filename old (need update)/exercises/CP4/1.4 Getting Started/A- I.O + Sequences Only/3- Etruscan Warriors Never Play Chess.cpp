#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    long long c;
    cin >> c;

    cout <<  (long long) (1 + sqrt(1 + 8 * c)) / 2 - 1 << '\n';

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

    return 0;
}