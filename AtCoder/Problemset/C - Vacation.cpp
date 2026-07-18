#include <bits/stdc++.h>

#define endl '\n'
#define min3(a,b,c) (min((a),min((b),(c))))
#define max3(a,b,c) (max((a),max((b),(c))))

using namespace std;

const int MXN = 1e5+5;

vector<vector<int>> dp(MXN, vector<int>(4, -1));
vector<int> a(MXN);
vector<int> b(MXN);
vector<int> c(MXN);

int solve(int n, int option) {

    if (dp[n][option] != -1 ) return dp[n][option];

    if (option == 1) {
        return dp[n][option] = max(solve(n+1, 2), solve(n+1,3))+a[n];
    } else
    if (option == 2) {
        return dp[n][option] = max(solve(n+1, 1), solve(n+1,3))+b[n];
    } else
    if (option == 3) {
        return dp[n][option] = max(solve(n+1, 1), solve(n+1,2))+c[n];
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    dp[n][1] = a[n]; dp[n][2] = b[n]; dp[n][3] = c[n];

    cout << max3(solve(0, 1), solve(0, 2), solve(0, 3));

    return 0;
}