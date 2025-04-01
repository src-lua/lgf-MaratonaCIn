#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<ll> arr(1e7, 0);

    int x;
    int a;

    int mx_day = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> x;
        arr[a] += x;
        arr[a+k] -= x;

        mx_day = max(mx_day, a+k);
    }

    for (int i = 1; i <= mx_day; i++) {
        arr[i] += arr[i-1];
    }
    

    int c = 0;
    ll drinked = 0;

    deque<ll> pool;

    for (int i = 1; i <= mx_day; i++) {

        if (pool.size() >= k) {
            drinked -= pool.front();
            pool.pop_front();
        }        

        if (arr[i] - drinked >= m) {
            c++;
            drinked += m;
            pool.push_back(m);
        }
        else {
            drinked += arr[i];
            pool.push_back(m);
        }
    }

    cout << c << '\n';

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