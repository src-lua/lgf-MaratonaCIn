/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/606592/problem/A
 * Status:      AC
 * Created:     06-04-2026 21:45:52
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> arr2(1e5+10, 0);
    for (auto const &x: arr) arr2[x]++;

    vector<int> prefix(arr2.size()+1, 0);
    for (int i = 0; i < arr2.size(); i++) prefix[i+1] = prefix[i] + arr2[i];
    
    for (int i = 1; i <= k; i++) {
        cout << prefix.back()-prefix[i] << ' ';
    } cout << '\n';

    return 0;
}
