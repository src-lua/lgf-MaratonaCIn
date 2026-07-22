/**
 * Author:      Lua
 * Problem:     1753 - String Matching
 * Link:        https://cses.fi/problemset/task/1753
 * Status:      AC
 * Tags:        Strings, Z
 * Created:     22-07-2026 19:23:43
 **/

#include <bits/stdc++.h>

using namespace std;

#include "lib/string/z-function.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t; cin >> s >> t;
    cout << z_search(t, s).size() << '\n';

    return 0;
}
