/**
 * Author:      Lua
 * Problem:     K
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103049/problem/K
 * Status:      ~
 * Created:     12-07-2026 09:01:59
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    getline(cin, a, '\n');
    getline(cin, b, '\n');

    vector<int> freq_a(200), freq_b(200);

    for (auto &x : a) freq_a[x]++;
    for (auto &x : b) freq_b[x]++;

    for (int i = 0; i < 200; i++) {
        if (freq_a[i] != freq_b[i]) cout << char(i);
    } cout << '\n';
    
    return 0;
}
