/**
 * Author:      Lua
 * Problem:     E - Test
 * Link:        https://codeforces.com/problemset/problem/25/E
 * Status:      AC
 * Tags:        Strings, Z
 * Created:     22-07-2026 20:24:00
 **/

#include <bits/stdc++.h>

using namespace std;

#include "lib/string/z-function.hpp"

string solve(vector<string>& words) {
    string ans = words[0]; int n = words.size();

    for (int i = 1; i < n; i++) {
        if (z_search(words[i], ans).size() > 0) continue;
        
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
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string a, b, c; cin >> a >> b >> c;
    
    vector<string> arr = {a, b, c};

    size_t ans = INT_MAX;

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) 
    for (int k = 0; k < 3; k++) {
        if (i == j || i == k || j == k) continue;
        vector<string> test = {arr[i], arr[j], arr[k]};
        ans = min(ans, solve(test).size());
    }
    
    cout << ans << '\n';

    return 0;
}
