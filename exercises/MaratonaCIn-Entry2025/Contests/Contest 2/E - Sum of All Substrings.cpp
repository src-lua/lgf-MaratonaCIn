#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    vector<ll> prefix(n+1);
    prefix[0] = 0;

    for (ll i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + (i+1)*(s[i] - '0');
    }

    reverse(prefix.begin(), prefix.end());

    ll idx = 0;
    while (true) {
        if (idx+1 >= prefix.size()) prefix.push_back(0);
        prefix[idx+1] += prefix[idx]/10ll;
        prefix[idx] %= 10ll;
        if (prefix[idx+1] < 10ll) break;
        
        idx++;
    }
    
    reverse(prefix.begin(), prefix.end());

    int k = 0;
    if (prefix[0] == 0) k = 1;

    string answ;

    for (int i = k; i <= n; i++) {
        cout << prefix[i];
    }

    return 0;
}