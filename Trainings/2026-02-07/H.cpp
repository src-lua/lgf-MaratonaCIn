/**
 * Author:      Lua
 * Problem:     H - Palindrome Number
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/H
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve(int n, int sum, string& ans) {
    if (n <= 0) return void();
    if (sum >= 9) return solve(n - 1, sum - 9, ans), ans += "9", void();
    else return solve(n - 1, 0, ans), ans += to_string(0 + sum), void();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n, s;
        cin >> n >> s;
        if ((s % 2 && !(n % 2)) || (n * 9 < s)) {
            cout << "-1\n";
            continue;
        }

        string ans_;
        solve(n / 2, s / 2, ans_);
        string ans = ans_;
        reverse(ans.begin(), ans.end());

        int sum = 0;
        for (auto e : ans) {
            sum += e - '0';
        }
        sum *= 2;
        string mid = to_string(s - sum);

        if(ans[0] == '0') cout << "-1\n";
        else if (n % 2) cout << ans << mid << ans_ << '\n';
        else cout << ans << ans_ << '\n';
    }

    return 0;
}
