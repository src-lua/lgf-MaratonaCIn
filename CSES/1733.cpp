/**
 * Author:      Lua
 * Problem:     1733 - Finding Periods
 * Link:        https://cses.fi/problemset/task/1733
 * Status:      AC
 * Tags:        Strings, Z
 * Created:     22-07-2026 19:27:07
 **/

#include <bits/stdc++.h>

using namespace std;

#include "lib/string/z-function.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s; int n = s.size();
    auto z = z_function(s);

    for (int i = 0; i < n; i++) if(z[i] == n-i) cout << i << ' ';
    cout << n << '\n';

    return 0;
}
