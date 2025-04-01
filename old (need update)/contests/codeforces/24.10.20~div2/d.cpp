#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int get(int idx, vector<int>& dp, vector<int>& va, vector<int>& vb, vector<int>& prefix, int skipped) {

    if (dp[idx] != -1) return dp[idx];

    if (skipped >= prefix.back()) return 0;

    return dp[idx] = max(prefix[idx] - skipped + get(vb[idx]-1, dp, va, vb, prefix, skipped+va[idx])
              ,va[idx] + prefix[idx] - skipped);
}

int solve() {

    int n; cin >> n;

    vector<int> dp(n, -1);
    vector<int> va(n);
    vector<int> vb(n);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> vb[i];
    }

    vector<int> prefix; prefix.push_back(0);

    for (auto e : va) prefix.push_back(prefix.back()+e);

    cout << get(0, dp, va, vb, prefix, 0) << endl;
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}