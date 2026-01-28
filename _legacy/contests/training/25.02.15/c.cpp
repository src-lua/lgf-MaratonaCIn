#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int c = 0;
    ll curr_score = k;
    
    for (int i = 0; i < n; i++) {
        if (curr_score == 0) {
            curr_score = k;
            c++;
        }
        
        if (curr_score-arr[i] >= 0) {
            curr_score -= arr[i];
        }
    }
    if (curr_score == 0) c++;

    cout << c << endl << curr_score << endl;

    return 0;
}