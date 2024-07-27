#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

ll getn(ll k, ll n) { return ((k + n) * (n - k + 1)) / 2ll; }

int solve() {

    int n; cin >> n;
    
    vector<int> arr(n);
    map<int,int> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    sort(arr.begin(), arr.end());

    ll answ = 0;

    for (int i = n-1; i >= 2; i--) {
        
        if (--m[arr[i]]) {
            answ += getn(i-m[arr[i]] ,i-1);
        }
    }

    cout << answ << '\n'; 

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