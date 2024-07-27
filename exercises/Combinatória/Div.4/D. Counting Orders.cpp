#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int solve() {

    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    vector<int> arr;

    for (auto e : b) {
        arr.push_back(a.size() - (upper_bound(a.begin(), a.end(),e) - a.begin()));
    }

    sort(arr.begin(),arr.end());

    ll answ = 1;


    for (size_t i = 0; i < arr.size(); i++) {
        answ = ll(ll(answ) * ll(arr[i]-i)) % MOD;
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