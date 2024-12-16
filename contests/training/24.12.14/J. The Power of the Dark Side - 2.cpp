#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    vector<ll> total;
    vector<ll> parcial;
    vector<int> asdasdasd;

    ll a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        total.push_back(a + b + c); 
        parcial.push_back(a + b + c - max(a, max(b, c)));
        if (max(a,max(b,c)) <= 1) asdasdasd.push_back(0);
        else asdasdasd.push_back(1 );
    }

    sort(parcial.begin(), parcial.end());

    for (int i = 0; i < total.size(); i++) {
        auto e = total[i];
        cout << upper_bound(parcial.begin(), parcial.end(), e-2) - parcial.begin() - asdasdasd[i] << ' ';
    } cout << endl;
    

    return 0;
}