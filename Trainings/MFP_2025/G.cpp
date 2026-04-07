/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/G
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int n = s.size();

    string a = "", b = "";
    for (int i = 0; i < n/2; i++) {
        a.push_back(s[2*i]);
        b.push_back(s[2*i+1]);
    }

    cout << a << '\n' << b << '\n'; 
    

    return 0;
}
