/**
 * Author:      Lua
 * Problem:     J
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/103940/problem/J
 * Status:      AC
 * Created:     13-04-2026 21:23:46
 **/

#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<int>& freq, string& curr, int target_len, int& curr_k, int k) {
    if (curr.size() == target_len) {
        curr_k++;
        if (curr_k == k) return true;
        return false;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freq[i]--;
            curr.push_back('a' + i);
            
            if (dfs(freq, curr, target_len, curr_k, k)) return true;
            
            curr.pop_back();
            freq[i]++;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    string s;  cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int curr_k = 0;
    string curr = "";
    for (int len = 1; len <= n; len++) {
        if (dfs(freq, curr, len, curr_k, k)) {
            break;
        }
    }

    cout << curr << '\n';

    return 0;
}