/**
 * Author:      Lua
 * Problem:     E
 * Link:        https://codeforces.com/gym/106495/problem/E
 * Status:      AC
 * Created:     10-07-2026 08:10:03
 **/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;
int spf[MAXN];

void build() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;

    for (int i = 3; i * i < MAXN; i += 2) if (spf[i] == i) 
        for (int j = i * i; j < MAXN; j += i) 
            if (spf[j] == j) spf[j] = i;
}

vector<int> get_factors(int x) {
    vector<int> factors;
    
    while (x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    build();

    int n, q; cin >> n >> q;

    vector<pair<vector<int>, int>> arr(n);
    for (int i = 0; i < n; i++) 
        arr[i] = {get_factors(i+1), i+1};
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++) {
        int k; cin >> k; k--;
        cout << arr[k].second << '\n';
    }

    return 0;
}
