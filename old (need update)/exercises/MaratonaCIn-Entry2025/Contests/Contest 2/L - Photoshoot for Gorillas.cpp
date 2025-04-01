#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int r, c; cin >> r >> c;

    ll k; cin >> k;

    int w; cin >> w;

    vector<int> heights(w);
    for (int i = 0; i < w; i++) cin >> heights[i];
    
    vector<ll> arr;

    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            arr.push_back(
                    min(
                    
                    min((min(i, r-i-1ll)+1ll), r-k+1ll)
                    ,k)
                    
                    *         
                    
                    min(
                    min((min(j, c-j-1ll) + 1ll), c-k+1ll)
                    ,k)
                );
        }
    }

    sort(arr.rbegin(), arr.rend());
    sort(heights.rbegin(), heights.rend());

    ll answ = 0;

    for (size_t i = 0; i < heights.size(); i++) {
        answ += heights[i]*arr[i];
    }
    
    cout << answ << endl;

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