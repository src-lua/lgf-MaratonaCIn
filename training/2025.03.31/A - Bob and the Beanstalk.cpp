/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[Bob and the Beanstalk](https://codeforces.com/gym/105740/problem/A)
Rating: NOT DEFINED
Tags: Implementation; Prefix Sum;

Date: 2025-03-29
Status: Accepted during contest
*/


#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> prefix(n+1);
    prefix[0] = 0;
    int answ = 0;
    int pos = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
        answ += 1;
        pos += min(prefix[i+1]-pos, k);
    }

    if (prefix[n]-pos > 0)
        answ += ((prefix[n]-pos +k-1)/k);

    cout << answ << '\n';

    return 0;
}