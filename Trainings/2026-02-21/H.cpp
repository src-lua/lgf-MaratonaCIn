/**
 * Author:      Lua
 * Problem:     H - Buying Products
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101915/problem/H
 * Status:      AC
 * Created:     21-02-2026 08:03:55
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) {
        int n, k; cin >> n >> k;

        vector<int> pool; pool.reserve(2*n);

        for (int i = 0; i < n; i++) {
            array<int, 3> arr;
            for (auto & x : arr) cin >> x;
            sort(arr.begin(), arr.end());
            pool.push_back(arr[0]);
            pool.push_back(arr[1]);
        }
        
        sort(pool.begin(), pool.end());

        cout << accumulate(pool.begin(), pool.begin()+k, 0LL) << '\n';
    }

    return 0;
}
