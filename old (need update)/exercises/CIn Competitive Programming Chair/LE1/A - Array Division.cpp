#include <bits/stdc++.h>

#define endl '\n'
using ll = long long;

using namespace std;

bool solve(ll m, vector<ll>& arr, int k) {
    ll sum = 0;
    int c = 1;

    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i] < m) sum += arr[i];
        else {
            sum = arr[i];
            c++;
        }
    }

    return c <= k;
}


ll binarySearch(ll l, ll r, vector<ll>& arr, int target) {
    ll init_l = l;
    ll init_r = r;
    ll answ = l;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        // If NOT SOLVE, ignore left half
        if (! (solve(m, arr, target)) )
            l = m + 1;

        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }

    return min(init_r, max(init_l, answ - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll l = *max_element(arr.begin(), arr.end());
    ll r = LLONG_MAX;

    cout << binarySearch(l, r, arr, k) << '\n';

    return 0;
}