/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://codeforces.com/gym/106495/problem/G
 * Status:      AC
 * Created:     10-07-2026 08:10:03
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    set<int> ss;
    for (int i = 1; i <= n; i++) ss.insert(i);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (ss.count(x)) ss.erase(x); 
        else ans++;
    }

    cout << ans << '\n';

    return 0;
}
