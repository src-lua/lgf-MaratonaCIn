/**
 * Author:      Lua
 * Problem:     A - Printing Books
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/A
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

pair<ll, bool> solve(ll init, ll digits) {
    if (digits == 0) return {0, true};

    string str = to_string(init);
    int next = str.size();
    ll next_power = pow(10, next);

    ll curr = min(next_power - init, digits/next);
    ll remaining = digits - curr * next;

    if (curr == 0) return {0, false};

    auto [a, b] = solve(init+curr, remaining);
    return {curr + a, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) {
        ll n, k; cin >> n >> k; 
        auto [a, b] = solve(k, n);
        cout << (b ? a : -1) << '\n';
    }

    return 0;
}
