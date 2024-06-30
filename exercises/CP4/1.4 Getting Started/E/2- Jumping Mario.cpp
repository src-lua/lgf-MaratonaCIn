#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n; cin >> n;

    int x, prev;
    int low = 0, high = 0;

    cin >> prev;

    for (int i = 0; i < n-1; i++) {
        cin >> x;

        if (x < prev) low++;
        else if (x > prev) high++;

        prev = x;
    }

    cout << high << ' ' << low <<'\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc;
    cin >> tc;
    while (tc--) {
        cout << "Case " << ++c << ": ";
        solve();
    }

    return 0;
}