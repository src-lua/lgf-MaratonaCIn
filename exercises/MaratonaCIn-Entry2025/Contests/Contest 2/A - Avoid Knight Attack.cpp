#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int dx[] = { 2, 1,-1,-2,-2,-1, 1, 2};
const int dy[] = { 1, 2, 2, 1,-1,-2,-2,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    int m; cin >> m;

    ll x, y;

    set<ll> pos;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;

        pos.insert(n * x + y);

        for (int d = 0; d < 8; d++) {
            ll a = x + dx[d];
            ll b = y + dy[d];

            if (!(a < 0 || a >= n || b < 0 || b >= n)) 
                pos.insert(n * a + b);
        }
    }
    
    cout << n*n - pos.size() << endl;

    return 0;
}