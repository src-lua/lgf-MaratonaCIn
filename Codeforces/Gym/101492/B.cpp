/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/gym/101492/problem/B
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;

    if ((n * (n+1)) % 4 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    ll target = (n * (n+1)) / 4;

    set<int> A; ll sum = 0;
    for (int i = n; i > 0; i--) {
        if (sum + i <= target) {
            sum += i;
            A.insert(i);
        }
    }
    
    for (int i = 1; i <= n; i++) cout << (A.count(i) ? "-" : "+");
    cout << '\n';

    return 0;
}
