/**
 * Author:      Lua
 * Problem:     M
 * Link:        https://vjudge.net/contest/796519#problem/M
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    n++;
    string s = to_string(n);

    for (auto &c : s) if (c == '0') c = '1';
    cout << s << '\n'; 

    return 0;
}
