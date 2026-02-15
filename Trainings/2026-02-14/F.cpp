/**
 * Author:      Lua
 * Problem:     F - Musical Chairs
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/102263/problem/F
 * Status:      AC
 * Created:     14-02-2026 13:45:39
 **/

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int MXN = 1e3+10;

vector<vector<int>> memo(MXN, vector<int>(MXN, -1));
bool solve(ll round, ll pos, ll n, vector<ll>& loose, vector<ll>& len) {
    if (memo[round][pos] != -1) return memo[round][pos];
    if (round == n-1) return memo[round][pos] = 1;

    ll curr_sz = n - round; 
    ll rmv = loose[round];
    bool ans = false;
    
    for (ll m : { -len[round], len[round] }) {
        ll next = ((pos + m) % curr_sz + curr_sz) % curr_sz;

        if (next != rmv && solve(round + 1, next - (next > rmv ? 1 : 0), n, loose, len)) 
            return memo[round][pos] = 1;
    }

    return memo[round][pos] = 0;
}

void fix_idx(vector<ll>& chair) {
    set<int> curr;
    for (int i = 0; i < chair.size() + 1; i++) curr.insert(i+1);
    
    for (auto & id : chair) {
        auto prev = id;
        id = (distance(curr.begin(), curr.find(id)));
        curr.erase(prev);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, pos; cin >> n >> pos;
    vector<ll> len(n-1); for (auto & x : len) cin >> x;
    vector<ll> chair(n-1); for (auto &x : chair) cin >> x;

    fix_idx(chair);

    cout << (solve(0, pos-1, n, chair, len) ? "Yes\n" : "No\n");

    return 0;
}
