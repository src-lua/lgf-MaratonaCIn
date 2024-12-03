#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

    int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> left((n+1)/2);
    vector<int> right(n/2);
    map<int, int> m;

    for (int i = 0; i < (n+1)/2; i++) {
        cin >> left[i];
    }

    for (int i = 0; i < n/2; i++) {
        cin >> right[i];
        m[right[i]] = (n+1)/2 + i;
    }

    ll suml = 0;
    ll sumr = 0;

    for (auto e : left) suml += e; 
    for (auto e :right) sumr += e; 
    
    if ((sumr - suml) % 2 != 0) {
        cout << "NO\n";
        return 0;
    } 

    sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++) {
        auto l = left[i];
        if ((sumr - suml) / 2 + l == *lower_bound(right.begin(), right.end(), (sumr - suml) / 2 + l)) {
            cout << "YES\n";
            cout << i+1 << ' ' << m[(sumr - suml) / 2 + l] + 1;
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}