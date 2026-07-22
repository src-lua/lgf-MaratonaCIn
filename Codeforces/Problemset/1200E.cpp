/**
 * Author:      Lua
 * Problem:     E - Compress Words
 * Link:        https://codeforces.com/problemset/problem/1200/E
 * Status:      AC
 * Tags:        Strings, Z
 * Created:     22-07-2026 19:35:54
 **/

#include <bits/stdc++.h>

#include "lib/string/z-function.hpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<string> words(n); for(auto &x: words) cin >> x;
    
    string ans = words[0];

    for (int i = 1; i < n; i++) {
        auto w = ans.substr(max(0,(int)ans.size()-(int)words[i].size()));
        auto z = z_function(words[i] + '#' + w);

        int overlap = 0;
        for (int j = words[i].size() + 1; j < z.size(); j++) {
            if (z[j] == (int)z.size() - j) {
                overlap = z[j];
                break; 
            }
        }
    
        ans += words[i].substr(overlap);
    }

    cout << ans << '\n';

    return 0;
}
