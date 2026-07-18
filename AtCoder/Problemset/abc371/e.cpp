#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

// Time complexity: O(n)
ll comb (ll n) {
    ll answ = 1;
    for (int i = 2; i <= n; i++) {
        answ  = (answ * i);
    }
    return answ;
    
}

ll comb(ll n, ll k) {
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    map<int, int> m;
    int reps = 0;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (m[x]++ != 0) {
            reps++;
        }
    }

    cout << 
    

    return 0;
}