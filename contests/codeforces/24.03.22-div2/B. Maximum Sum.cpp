#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = INT_MAX;

vector<int> arr(1e6);

int kadane(int size)
{
    ll max_sum = 0, current_sum = 0;
 
    for (int i = 0; i < size; i++) {
        current_sum = current_sum + arr[i];
        if (max_sum < current_sum)
            max_sum = current_sum;
 
        if (current_sum < 0)
            current_sum = 0;
    }
    return max_sum % MOD;
}

ll power_mod(int n) {
    ll power = 1;

    for (int i = 0; i < n; i++)
    {
        power = (power * 2) % MOD;
    }

    return power;
    
}

int solve() {

    int n,k; cin >> n >> k;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum = (sum + arr[i]) % MOD;
    }

    ll best = kadane(n);

    sum = (sum + (best*(power_mod(k)-1) % MOD)) % MOD;
    
    if (sum < 0) sum += MOD;

    cout << sum << endl;

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }


    return 0;
}