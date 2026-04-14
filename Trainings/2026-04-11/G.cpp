/**
 * Author:      Lua
 * Problem:     G
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/G
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; 

    vector<int> viagens(n - 1), stations(n); 
    for (auto &x : viagens) cin >> x; 
    for (auto &x : stations) cin >> x; 

    vector<pair<ll, ll>> ans1; ll tmp = 0; 
    for (int i = 0; i < n; i++) {
        ans1.push_back({tmp, tmp + stations[i]}); 
        tmp += stations[i]; 

        if (i < n - 1) {
           tmp += viagens[i];  
        }
    }

    reverse(viagens.begin(), viagens.end()); 
    reverse(stations.begin(), stations.end());
    vector<pair<ll, ll>> ans2; 
    // trem 2
    ll temp2 = 0; 
    for (int i = 0; i < n; i++) {
        ans2.push_back({temp2, temp2 + stations[i]}); 
        temp2 += stations[i]; 

        if (i < n - 1) {
           temp2 += viagens[i];  
        }
    }

    reverse(ans2.begin(), ans2.end()); 
    // merge 

    ll total = 0; 
    for (int i = 0; i < n; i++) {
        auto [l1, r1] = ans1[i]; 
        auto [l2, r2] = ans2[i]; 

        total += max(
            0LL, 
            min(r1, r2) - max(l1, l2)
        ); 
    }

    cout << total << '\n'; 
    return 0;
}
