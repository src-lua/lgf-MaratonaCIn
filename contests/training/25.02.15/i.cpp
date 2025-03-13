#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n, vector<ll>());

    ll a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    set<ll> second_order;
    map<ll, ll> third_order;

    for (auto e : adj[0]) {
        second_order.insert(e);
    }

    for (auto e : second_order) {
        for (auto f : adj[e]) {
            if (f != 0) {
                third_order[f]++; 
            }
        }
    }

    ll answ  = 0;

    for (auto e : third_order) {
        answ += e.second*(e.second-1);
    }

    cout << answ << endl;

    return 0;
}