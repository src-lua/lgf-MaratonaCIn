/**
 * Author:      Lua
 * Problem:     J - Spilt the String
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/J
 * Status:      AC
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

vector<int> P;

void sieve(ll n) {
    vector<bool> prime(n + 1, true);
 
    for (ll p = 2; p <= n; p++) {
        if (prime[p] == true) {
            P.push_back(p);

            for (ll i = p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve(1e5);

    int tc; cin >> tc; 
    
    cin.ignore();
    while(tc--) {
        string s; getline(cin, s);
        stringstream ss(s);

        int n = s.size();

        vector<int> arr;
        while(ss >> s) arr.push_back(s.size());

        ll accum = accumulate(arr.begin(), arr.end(), 0LL);

        bool flag = false;

        for (size_t i = 0; i < P.size(); i++) {
            ll target = accum + arr.size()-P[i];
            if (target % P[i]) continue; target /= P[i];
            
            ll curr = 0;
            flag = true;
            for (size_t j = 0; j < arr.size(); j++) {
                if (curr == target) curr = 0;

                int next = curr + arr[j] + (curr == 0 ? 0 : 1);
                if (next > target) {flag = false; break;}
                curr = next;
            }

            if (curr != target) flag = false;

            if (flag) {
                cout << "YES\n";
                break;
            }   
        }    
        if (!flag) cout << "NO\n";
    }

    return 0;
}
