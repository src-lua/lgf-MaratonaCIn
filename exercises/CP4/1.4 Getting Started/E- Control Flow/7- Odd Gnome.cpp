#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n;
    cin >> n;

    int x;
    int prev; cin >> prev;
    int answ = 0;

    for (int i = 2; i <= n; i++) {
        cin >> x;

        if (!answ && (x != prev+1)) {
            answ = i;
        }

        prev = x;
    }

    cout << answ << '\n';

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