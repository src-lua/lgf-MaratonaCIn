/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/701070/problem/B
 * Status:      ~
 * Tags:        
 * Created:     18-07-2026 08:31:07
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> rato(n); for (auto &x : rato) cin >> x;
    vector<ll> buraco(n+1); for (auto &x : buraco) cin >> x;

    vector<ll> distancia_percorrida(n+1);
    vector<ll> rato_que_caiu_nesse_buraco(n+1, -1);

    sort(rato.begin(), rato.end());
    sort(buraco.begin(), buraco.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        distancia_percorrida[i] = abs(rato[i] - buraco[i]);
        rato_que_caiu_nesse_buraco[i] = i;
        ans += distancia_percorrida[i];
    }

    ll curr = ans;

    for (int i = n-1; i >= 0; i--) {
        rato_que_caiu_nesse_buraco[i+1] = rato_que_caiu_nesse_buraco[i];
        rato_que_caiu_nesse_buraco[i] = -1;
        
        ll new_ans = curr;
        new_ans -= distancia_percorrida[i];

        distancia_percorrida[i+1] = abs(buraco[i+1] - rato[rato_que_caiu_nesse_buraco[i+1]]);
        
        new_ans += distancia_percorrida[i+1];
        distancia_percorrida[i] = 0;

        ans = min(ans, new_ans);
        curr = new_ans; 
    }
    
    cout << ans << '\n';    

    return 0;
}
