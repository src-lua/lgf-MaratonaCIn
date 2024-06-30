#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int c = 0;
    int k;

    while (cin >> n) {
        int minvalue = INT_MAX;
        int maxvalue = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> k;

            minvalue = min(minvalue, k);
            maxvalue = max(maxvalue, k);
        }

        cout << "Case " << ++c << ": " << minvalue << ' ' << maxvalue << ' ' << maxvalue-minvalue << '\n';
    }

    return 0;
}