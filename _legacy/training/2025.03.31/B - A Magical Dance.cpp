/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[A Magical Dance](https://codeforces.com/gym/105740/problem/B)
Rating: NOT DEFINED
Tags: Dynamic Programming; Implementation;

Date: 2025-03-29
Status: Accepted during contest
*/


#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// 0 -> north   1 -> east   2 -> south   3 -> west
vector<vector<int>> dp(1e6, vector<int>(4, -1));
int solve(string& s, int idx, int facing_dir) {
    if (dp[idx][facing_dir] != -1) return dp[idx][facing_dir];
    if (idx >= s.size()) return 0;
    int answ = 0;

    char dir;

    if(facing_dir == 0) dir = 'N';
    else if (facing_dir == 1) dir = 'E';
    else if (facing_dir == 2) dir = 'S';
    else if (facing_dir == 3) dir = 'W'; 

    if (s[idx] == dir) answ = 1;

    return dp[idx][facing_dir] = answ + max(
        solve(s, idx+1, (facing_dir+1)%4),
        solve(s, idx+1, (facing_dir-1+4)%4)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    cout << max({
        solve(s, 0, 0),
        solve(s, 0, 1),
        solve(s, 0, 2),
        solve(s, 0, 3),
    }) << '\n';

    return 0;
}