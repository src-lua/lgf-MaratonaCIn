/**
 * Author:      Lua
 * Problem:     G - Super Subarray
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/G
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;

    ll max_sum = accumulate(arr.begin(), arr.end(), 0LL);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll curr_lcm = arr[i];
        ll curr_sum = arr[i];
        ans++;
        
        for (int j = i+1; j < n; j++) {
            curr_sum += arr[j];
            curr_lcm = lcm(curr_lcm, arr[j]);
            if (curr_lcm > max_sum) break;
            if (curr_sum % curr_lcm == 0) ans++;
        }
    }

    cout << ans << '\n';
}
    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
