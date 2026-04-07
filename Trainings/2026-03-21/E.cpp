/**
 * Author:      Lua
 * Problem:     E - Excellent Engineers
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/E
 * Status:      ~
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int,int,int>;

void solve() {
    int n; cin >> n;
    vector<iii> arr(n);
    for (auto &[x,  y, z] : arr) cin >> x >> y >> z;

    auto lt = [](iii a, iii b){
        auto [x, y, z] = a;
        auto [u, v, w] = b;
        
        return (x > u && y > v && z > w);
    };

    stable_sort(arr.rbegin(), arr.rend(), lt);

    cout << " ======\n ";
    for (auto &[x, y, z] : arr) 
    cout << x << ' ' << y << ' ' << z << '\n';
    cout << " ======\n ";
    cout << endl;
    

    auto ref = arr[0];

    int i = 1;
    while (i < n && !lt(arr[i] , ref)) i++;

    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    freopen("E_1.in", "r", stdin);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
