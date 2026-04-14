/**
 * Author:      Lua
 * Problem:     B
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/B
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<ll> &palindromes) {
    ll l, r; cin >> l >> r;

    auto lo = lower_bound(palindromes.begin(), palindromes.end(), l);
    auto hi = upper_bound(palindromes.begin(), palindromes.end(), r);

    cout << (hi - lo) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<ll> palindromes;

    for (int bits = 1; bits <= 16; bits++) {
        for (int mask = (1 << (bits-1)); mask < (1 << bits); mask++) {
            ll odd = mask;
            for (int i = 1; i < bits; i++)
                odd = (odd << 1) | ((mask >> i) & 1);

            ll even = mask;
            for (int i = 0; i < bits; i++)
                even = (even << 1) | ((mask >> i) & 1);

            if (odd < (1LL<<31)) palindromes.push_back(odd);
            if (even < (1LL<<31)) palindromes.push_back(even);
        }
    }

    sort(palindromes.begin(), palindromes.end());
    palindromes.erase(unique(palindromes.begin(), palindromes.end()), palindromes.end());

    int tc; cin >> tc; while(tc--) solve(palindromes);

    return 0;
}
