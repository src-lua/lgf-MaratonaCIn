/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://vjudge.net/contest/783478#problem/L
 * Status:      AC
 * Created:     29-01-2026 11:21:13
 **/

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    
    
    for (int i = 0; i < n-2; i++) {
        if (arr[i+0] < arr[i+1] + arr[i+2] &&
            arr[i+1] < arr[i+0] + arr[i+2] &&
            arr[i+2] < arr[i+1] + arr[i+0]) {
                cout << "possible\n";
                return 0;
            }
    }

    cout << "impossible\n";
    return 0;
}