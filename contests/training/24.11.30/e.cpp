#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;
const int MOD = 1e9+7;

map<int, map<int, int>> C;

int solve(int N, int k, int pre) {
    if (k == 0 || N == k) return 1;
    if (C[N][k] != 0) return C[N][k];

    auto newpre = solve(N-1, k-1, pre); 
    auto answ = (pre + solve (N-1, k-1, newpre)) % MOD;
    
    return answ;
    
    (solve(N, k-1) + ) % MOD;


    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
    }
    return C[N][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> ni(n);
    vector<int> ki(n);

    for (int i = 0; i < n; i++) cin >> ni[i];
    for (int i = 0; i < n; i++) cin >> ki[i];

    int ni_max = *max_element(ni.begin(), ni.end());
    int ki_max = *max_element(ki.begin(), ki.end());
    

    for (int i = 0; i < n; i++) {
        cout << solve(ni[i]+1, ki[i]+1) << endl;
        // cout << C[ni[i]][ki[i]] << endl;
    }


    return 0;
}