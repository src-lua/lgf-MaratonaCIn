/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/A
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    string curr = "";
    string rev = "";

    for (int i = 0; i < n; i++) {
        curr += char('a'+i) + rev;
        rev = curr; reverse(rev.begin(), rev.end());
        if (curr.size() > 1e5) break;
    }

    for (int i = 0; i < min(int(curr.size()), (int)1e5); i++) {
        cout << char(curr[i]);
    } cout << '\n';
    

    return 0;
}
