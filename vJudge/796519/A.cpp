/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://vjudge.net/contest/796519#problem/A
 * Status:      AC
 * Created:     14-03-2026 09:15:55
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i + 1 < n; i++)
        if (s[i] == s[i+1]) { cout << "Or not.\n"; return 0; }
    cout << "Odd.\n";
	
    return 0;
}
