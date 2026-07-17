/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103049/problem/H
 * Status:      ~
 * Created:     12-07-2026 09:01:59
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
    vector<int> a, b;
    for (int i = 0; i < n/2; i++) {
        a.push_back(arr[i]);
    }
    for (int i = n/2; i < n; i++) {
        b.push_back(arr[i]);
    }

    reverse(b.begin(), b.end());

    vector<int> ans;

    int i = 0;
    while (i < a.size() || i < b.size()) {
        if (i < b.size()) ans.push_back(b[i]);
        if (i < a.size()) ans.push_back(a[i]);
        i++;
    }

    reverse(ans.begin(), ans.end());

    for (auto &x : ans) cout << x << ' '; cout << '\n';

    return 0;
}
