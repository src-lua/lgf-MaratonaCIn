#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities, roads, target;
    cin >> cities >> roads >> target;

    vector<vector<int>> adj(cities+1); 

    int x, y;
    for (int i = 0; i < roads; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    if (target > roads) {
        cout << "Impossible";
        return 0;
    }
    
    int minbus = 1;

    for (int i = 1; i <= cities; i++) {
        if (adj[i].size() == 0) {
            cout << "Impossible";
            return 0;
        } else {

            if (adj[i].size() > 2) {
                minbus += adj[i].size()-2;
            }
        }
        
    }
    
    if (target < minbus) {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible";

    return 0;
}