/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://vjudge.net/contest/783478#problem/H
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> get(int n) {
    if (n == 1) return {"0","1"};

    auto a = get(n-1);
    vector<string> ans;

    for (auto e : a) ans.push_back(e + "0");
    reverse(a.begin(), a.end());
    for (auto e : a) ans.push_back(e + "1");
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n; for (auto e : get(n)) cout << e << '\n';

    return 0;
}