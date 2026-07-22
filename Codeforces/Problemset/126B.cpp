/**
 * Author:      Lua
 * Problem:     B - Password
 * Link:        https://codeforces.com/problemset/problem/126/B
 * Status:      AC
 * Tags:        Strings, Z, KMP, Busca Binária
 * Created:     22-07-2026 19:57:41
 **/

#include <bits/stdc++.h>

using namespace std;

#include "lib/string/z-function.hpp"

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     string s; cin >> s; int n = s.size();
//     auto z = z_function(s);

//     vector<int> idxs;
//     for (int i = n - 1; i > 0; i--) {
//         if (z[i] == n-i) idxs.push_back(n-i);
//     }

//     string t = s.substr(1, s.size()-2);
//     auto check = [&](int m) -> bool {
//         string p = s.substr(0, idxs[m]);
//         return z_search(p, t).size() > 0;
//     };

    
//     int l = 0, r = idxs.size()-1, ans = -1;
//     while (l <= r) {
//         int m = l + (r-l)/2;
        
//         if (check(m)) l = m + 1, ans = m;
//         else r = m - 1;
//     }
    
//     cout << (ans == -1 ? "Just a legend" : s.substr(0, idxs[ans])) << '\n';

//     return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s; int n = s.size();
    auto z = z_function(s);

    int mx_z = 0;
    for (int i = 0; i < n; i++) {
        if (z[i] == n-i && mx_z >= n-i) {
            cout << s.substr(0, n-i) << '\n';
            return 0;
        }
        mx_z = max(mx_z, z[i]);
    }
    
    cout << "Just a legend\n";
    return 0;
}