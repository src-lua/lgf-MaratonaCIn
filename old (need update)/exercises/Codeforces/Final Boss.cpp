#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
// O(n)
bool f (ll k, ll h, vector<ll>& damage, vector<ll>& cooldown) {
    ll sz = damage.size();
    ll sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += damage[i] * (k/cooldown[i] + 1);
        if (sum >= h) return true;
    }

    return false;
}

// Time Complexity: O(log(n)) * O(n); => O(n * log(n))
ll binarySearch(ll l, ll r, ll h, vector<ll>& damage, vector<ll>& cooldown) {
    ll answ;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        // If NOT SOLVE, ignore left half
        if (! (f(m, h, damage, cooldown)) )
            l = m + 1;

        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }

    return answ;
}

int solve() {

    int h, n; cin >> h >> n;
    vector<ll> damage(n);
    vector<ll> cooldown(n);
    for (int i = 0; i < n; i++) cin >> damage[i]; 
    for (int i = 0; i < n; i++) cin >> cooldown[i];
    
    cout << binarySearch(0, ll(4e10)+4ll, h, damage, cooldown) + 1ll << endl;    

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}