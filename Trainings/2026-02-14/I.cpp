/**
 * Author:      Lua
 * Problem:     I - Bashar and Hamada
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/I
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    
    sort(arr.begin(), arr.end());

    ll ans = arr.back() - arr.front(); 
    cout << ans;

    int l = 1, r = n-2;
    ll L = arr.front(), R = arr.back();
    int Ls = 1, Rs = 1;
    for (int i = 3; i <= n; i++) {
        ans += R; ans -= L;

        ll e;
        if (i % 2) {
            e = arr[r--];
            ans += (Ls-Rs)*e;
            R += e;
            Rs++;
        }
        else {
            e = arr[l++];    
            ans += (Ls-Rs)*e;
            L += e;
            Ls++;
        }

        cout << ' ' << ans;
    } cout << '\n';
    
    return 0;
}
