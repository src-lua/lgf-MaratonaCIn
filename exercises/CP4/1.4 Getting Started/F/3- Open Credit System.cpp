#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n;
    cin >> n;

    int x; cin >> x;

    int maxValue = x;
    int minValue = x;
    int answ = INT_MIN;


    for (int i = 1; i < n; i++) {
        cin >> x;

        answ = max(answ, max(maxValue - x, minValue - x));
        minValue = min(minValue, x);
        maxValue = max(maxValue, x);
    }

    cout << answ << endl;

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