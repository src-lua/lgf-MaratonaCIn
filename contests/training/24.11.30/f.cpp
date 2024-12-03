#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> freq;

    for (auto e : arr) {
        freq[e]++;
    }

    map<int, ll> prefix; prefix[0] = 0;
    for (auto [key, v] : freq) {
        prefix[key];
        auto it = prefix.find(key);
        --it;
        prefix[key] = it->second+ v;  
    }

    ll answ = 0;

    for (auto [i, v] : prefix) {
        bool flag = true;

        for (int j = 0; j <= k; j++) {
            if (i-j < 0) continue;
            if (prefix.count(i-j) == 0) {
                prefix[i-j];
                auto it = prefix.find(i-j);
                --it;

                answ = max(answ, v - it->second);

                ++it;
                prefix.erase(it);
                flag = false;
                break;
            }
        }
        if (flag) {
            answ = max(answ, v - prefix[max(i-k, 0)]);
        }
    }

    cout << answ << endl;

    return 0;
}