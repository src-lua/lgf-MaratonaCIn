/**
 * Author:      Lua
 * Problem:     F - A Missing Problem in TCPC2017
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/F
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) {
        int n; cin >> n;
        set<int> s; for (int i = 1; i <= n; i++) s.insert(i);
    
        for (int i = 0; i < n-1; i++) {
            int x; cin >> x;
            s.erase(x);
        }
        
        cout << *s.begin() << '\n';
    }

    return 0;
}
