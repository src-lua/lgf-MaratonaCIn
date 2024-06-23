#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);    
    
    int n, toppings;
    cin >> n >> toppings;

    vector<set<int>> adj(toppings+1);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x != y) {
            adj[x].insert(y);
            adj[y].insert(x);
        }
        else { // if x == y
            adj[x].insert(x);
        }
    }

    int c =0;
    for (int i = 1; i < toppings; i++) {
        if (adj[i].size()>=3) {
            c  = 0;
            for (auto e: adj[i]) {
                if (adj[e].size() >= 2) {
                    c++;
                    if (e == i) c--;
                }
            }
            if (c > 2) {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    
    cout << "possible\n";
    return 0;

}