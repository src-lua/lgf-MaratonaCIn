#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int passengers; cin >> passengers; 
    ll weight; cin >> weight;

    vector<ll> mass(passengers);
    vector<ll> strenght(passengers);

    for (int i = 0; i < passengers; i++) {
        cin >> mass[i];
        weight += mass[i];
    }
    
    for (int i = 0; i < passengers; i++)
    {
        cin >> strenght[i];
        strenght[i] += mass[i];
    }

    sort(strenght.rbegin(), strenght.rend());

    int c = 0;
    for (int i = 0; i < int(strenght.size()); i++) {
        weight -= strenght[i];
        c++;
        if (weight <= 0) break;
    }

    if (weight <= 0) cout <<  c << endl;
                else cout << -1 << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

int tc; cin >> tc; while (tc--) {
    solve();
}

    return 0;
}