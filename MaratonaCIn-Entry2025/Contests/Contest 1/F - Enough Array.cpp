#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    
    cin >> n >> k;

    ll answ = 0;

    vector<ll> arr(n);
    vector<ll> prefix(n + 1);
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int j = 1;

    for (int i = 1; i <= n; i++) {
        while (j <= n && prefix[i] - prefix[j - 1] >= k) {
            answ += -i + 1 + n;

            j++;
        }
    }

    cout << answ;

    return 0;
}