/**
 * Author:      Lua
 * Problem:     L
 * Link:        https://codeforces.com/group/btcK4I5D5f/contest/689113/problem/L
 * Status:      ~
 * Created:     02-05-2026 08:53:00
 **/

#include <bits/stdc++.h>

using namespace std;

map<int,int> queried;
int query(int i) {
    if (queried.count(i)) return queried[i];

    cout << "? " << i << endl;
    int ans; cin >> ans;

    return queried[i] = ans;
}

int guess(int i) {
    cout << "! " << i << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;

    vector<int> init(n+2); init[0] = 1;
    for (int i = 1; i < n+2; i++) init[i] = init[i-1]+i;
    auto get_idx = [&](int l, int i){
        return init[l]+i;
    };

    vector<int> guessed; guessed.reserve(n+2);
    guessed.push_back(1);

    int rem_l = 0;
    int rem_r = 0;

    for (int l = 1; l <= n; l++) {
        int x = get_idx(l, rem_l);
        int q = query(x);
        if (q == 1) {
            guessed.push_back(x);
            rem_r++;
        }
        else {
            guessed.push_back(x+1);
            rem_l++;
        }
    }
    
    int l = 0;
    int r = guessed.size()-1;
    int ans = -1;

    while (l <= r) {
        int m = l + (r-l)/2;

        if (query(guessed[m]) == 1) {
            ans = guessed[m];
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return guess(ans);
}
