/**
 * Author:      Lua
 * Problem:     C - Shahhoud Training Hussain
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/C
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while (tc--) {
        ll k, p , n; cin >> k >> p >> n;
    
        cout << n * max(k-p, 0LL) << '\n';   
    }

    return 0;
}
