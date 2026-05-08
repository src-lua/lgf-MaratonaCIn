/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/H
 * Status:      ~
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
vector<int> where(21);

string abc = "ABC";

void move(int x, int from, int to) {
    if (from == to) return;

    for (int i = x - 1; i >= 1; i--) 
        move(i, where[i], 3-from-to);
    
    ans.push_back(abc[from] + string(" ") + abc[to]);
    where[x] = to;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
  
    int k; 

    cin >> k; for (int i = 0; i < k; i++) {
        int x; cin >> x;
        where[x] = 0;
    }

    cin >> k; for (int i = 0; i < k; i++) {
        int x; cin >> x;
        where[x] = 1;
    }

    cin >> k; for (int i = 0; i < k; i++) {
        int x; cin >> x;
        where[x] = 2;
    }
    
    for (int i = n; i >= 1; i--) {
        move(i, where[i], 1);
    }
    
    cout << ans.size() << '\n';
    for (auto &x : ans) cout << x << '\n';

    return 0;
}
