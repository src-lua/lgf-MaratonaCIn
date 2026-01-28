/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://vjudge.net/contest/781528#problem/E
 * Status:      AC
 * Created:     28-01-2026 16:15:44
 **/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n != 0) {
        stack<int> s;
        int target = 1;
        vector<int> arr(n);
        for (auto& x : arr) cin >> x;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() == target) {
                s.pop();
                target++;
            }

            int x;
            x = arr[i];
            if (x == target)
                target++;
            else {
                if (x > (s.empty() ? INT_MAX : s.top())) {
                    cout << "no\n";
                    goto END;
                } else {
                    s.push(x);
                }
            }
        }

        cout << "yes\n";
    END:
        cin >> n;
    }

    return 0;
}