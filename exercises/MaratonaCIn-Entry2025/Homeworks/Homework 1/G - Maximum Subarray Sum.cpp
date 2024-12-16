#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

ll kadane(vector<ll> &arr) { // Max Subarray Sum
    ll answ = arr[0];
    ll maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        answ = max(answ, maxEnding);
    }

    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << kadane(arr);

    return 0;
}