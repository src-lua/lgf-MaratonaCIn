/**
 * Author:      Lua
 * Problem:     F
 * Link:        https://vjudge.net/contest/796519#problem/F
 * Status:      ~
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; 
    cin >> s; 
    int n = s.size();
    
    int curr = 0;
    int mn = 0, mn_idx = 0;
    int mx = 0, mx_idx = 0;
    
    for (int i = 1; i <= n; i++) {
        curr += (s[i - 1] == 'B' ? +1 : -1);
        
        if (curr < mn) {
            mn = curr;
            mn_idx = i;
        }
        if (curr > mx) {
            mx = curr;
            mx_idx = i;
        }
    }
    
    int start = min(mn_idx, mx_idx) + 1;
    int end = max(mn_idx, mx_idx);
    
    cout << start << " " << end << "\n";

    return 0;
}
