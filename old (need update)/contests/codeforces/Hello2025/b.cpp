#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    ll n, k; cin >> n >> k;

    vector<ll> arr(n);
    map<ll,ll> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<int> freqs;

    for (auto [k,v] : freq) {
        freqs.push_back(v);
    }
    
    sort(freqs.begin(), freqs.end());

    ll c = 0;

    for(auto e : freqs) {
        if (k >= e) {
            k-=e;
            c++;
        }
        else {
            break;
        }
    }

    cout << max(1ll, ll(freqs.size()) - c) << endl;

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