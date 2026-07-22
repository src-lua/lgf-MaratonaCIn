/**
 * Author:      Lua
 * Problem:     A
 * Link:        https://codeforces.com/gym/106167/problem/A
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n; 

    if (__popcount(n-1) > 2) cout << "impossible\n";
    else cout << ((n-1) & -(n-1))+1 << '\n';

    return 0;
}
