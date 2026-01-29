/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://vjudge.net/contest/782309#problem/J
 * Status:      AC
 * Created:     29-01-2026 11:06:02
 **/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int n; cin >> n;
    vector<int> adj(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        adj[i] = x;
    }

    for (int i = 0; i < n; i++) {
        if (adj[adj[adj[i]]] == i) {
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}