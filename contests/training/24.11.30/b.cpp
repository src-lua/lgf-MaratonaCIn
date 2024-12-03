#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    ll answ = s.size() + t.size();

    for (int i = 0; i < min(s.size(), t.size())+1; i++) {
        if (i == min(s.size(), t.size()) || s[i] != t[i]) {
            if (i != 0) answ -= i-1;
            break;
        }
    }
    
    cout << answ;

    return 0;
}