/**
 * Author:      Lua
 * Problem:     J - Thanos Power
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/J
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;

    ll ans = 0;
    int carry = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        int curr = s[i]-'0' + carry;

        if (curr < 5) {
            ans += curr;
            carry = 0;
        }
        else if (curr > 5) {
            ans += 10-curr;
            carry = 1;
        }
        else if (curr == 5) {
            if (i > 0 && (s[i-1] - '0' >= 5)) {
                ans += 5;
                carry = 1;
            }
            else {
                ans += 5;
                carry = 0;
            }
        }
    }

    cout << ans + carry << '\n';

    return 0;
}
