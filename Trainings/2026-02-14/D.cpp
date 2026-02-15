/**
 * Author:      Lua
 * Problem:     D - Meeting Bahosain
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/D
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int g = b[0];
    for (auto const & x : b) g = gcd(g, x);

    for (auto &x : a) x -= a[0];

    for (auto const &x : a) if (x % g) {
        cout << "No\n";
        return 0;
    } 

    cout << "Yes\n";
    return 0;
}
