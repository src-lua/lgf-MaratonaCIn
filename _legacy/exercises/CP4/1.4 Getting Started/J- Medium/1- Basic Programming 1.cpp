#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = unsigned long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    if (t == 1) {
        cout << 7 << endl;
        return 0;
    } else 
    
    if (t == 2) {
        ll a, b; cin >> a >> b;
        
        if (a > b) cout << "Bigger"  << endl;
        if (a < b) cout << "Smaller" << endl;
        else       cout << "Equal"   << endl;

        return 0;
    } else 
    
    if (t == 3) {
        vector<ll> v(3);
        
        cin >> v[0] >> v[1] >> v[2];
        
        sort(v.begin(), v.end());
        
        cout << v[1] << endl;
        return 0;
    } else

    if (t == 4) {
        ll x;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }

        cout << sum << endl;
        return 0;
    } else

    if (t == 5) {
        ll x;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> x;
            if (x % 2 == 0) sum += x;
        }

        cout << sum << endl;
        return 0;
        
    } else

    if (t == 6) {
        ll x;
        for (ll i = 0; i < n; i++) {
            cin >> x;
            cout << char((x % 26) + 'a');
        } cout << endl;
        
        return 0;
    } else

    if (t == 7) {
        vector<ll> v(n);

        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }

        unordered_set<ll> ss;

        ll idx = 0;
        while(1) {
            idx = v[idx];
            if (idx >= n) {
                cout << "Out" << endl;
                return 0;
            } else if (idx == n-1) {
                cout << "Done" << endl;
                return 0;
            } else { 
                if (ss.count(idx) != 0) {
                    cout << "Cyclic" << endl;
                    return 0;
                } else {
                    ss.insert(idx);
                }
            }
        }
    }
}