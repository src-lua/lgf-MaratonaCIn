/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/gym/101492/problem/E
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> arr(n);

    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    ll ans = 0;

    while(arr.size() >= 4) {
        if (arr[arr.size()-1] + arr[arr.size()-2] + 2 * arr[0] >
            arr[arr.size()-1] + arr[0] + 2 * arr[1]) {
                ans += arr[arr.size()-1] + arr[0] + 2 * arr[1];
            }
            else ans += arr[arr.size()-1] + arr[arr.size()-2] + 2 * arr[0];
        arr.pop_back(); arr.pop_back();
    }

    if (arr.size() == 3) {
        ans += arr[2] + arr[1] + arr[0];
    }

    else if (arr.size() == 2) {
        ans += arr[1];
    }

    else if (arr.size() == 1) {
        ans += arr[0];
    }

    cout << ans << endl;

    return 0;
}





0
1
2
1 1
3
1 2
2 1
1 1 1
