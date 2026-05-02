/**
 * Author:      Lua
 * Problem:     D
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/D
 * Status:      ~
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int j = 1;
    while(j < s.size() && s[j] == s[j-1]) j++;

    for (int i = 0; i < k; i++) {
        string t; cin >> t;

        int k = 1;
        while(k < t.size() && t[k] == t[k-1]) k++;

        cout << (s[0] != t[0] ? s.size() + t.size() : s.size() + t.size() - min(j, k)) << '\n';
    }

    return 0;
}
