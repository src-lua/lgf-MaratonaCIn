#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

void getsum(int l, int r, vector<int>& arr, vector<ll>& sum, ll curr_sum = 0) {
    if (l == r) {
        sum.push_back(curr_sum);
        return;
    }

    getsum(l+1, r, arr, sum, curr_sum);
    getsum(l+1, r, arr, sum, curr_sum + arr[l]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<ll> left, right;
    
    getsum(0, n/2, arr, left);
    getsum(n/2, n, arr, right);

    ll answ = 0;

    sort(right.begin(), right.end());

    for (auto e : left) {
        answ += upper_bound(right.begin(), right.end(), x-e) - lower_bound(right.begin(), right.end(), x-e);
    }

    cout << answ;

    return 0;
}