#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll w, b; cin >> w >> b;
    
    cout << min(b, w+1) << endl;
 
    return 0;
}