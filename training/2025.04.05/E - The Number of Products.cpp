#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int k = 0;
    vector<vector<ll>> answ(n,vector<ll>(2,0));
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) k = (k+1)%2;
        answ[0][k]++;
    }
    
    for (int i = 1; i < n; i++) {
        answ[i][0]--;
        if (arr[i-1] < 0) {
            answ[i][1] += answ[i-1][0];
            answ[i][0] += answ[i-1][1];
        }
        else {
            answ[i][1] += answ[i-1][1];
            answ[i][0] += answ[i-1][0];
        }
    }

    ll pos, neg;
    pos = neg = 0;

    for (int i = 0; i < n; i++) {
        pos += answ[i][0];
        neg += answ[i][1];
    }

    cout << neg << ' ' << pos << '\n';

    return 0;
}