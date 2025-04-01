#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int getansw(string& s, string& t, int s_idx, int t_idx) {
    if (t_idx > t.size()) return t_idx - s_idx;

    if (s[s_idx] == t[t_idx]) return getansw(s, t, s_idx+1, t_idx+1);

    return 1 + min(getansw(s,t,s_idx+1,t_idx+1), 
               getansw(s,t,s_idx,t_idx+1));
}

int solve() {

    string s, t;
    getline(cin, s);
    getline(cin, t);

    if (s.size() > t.size()) swap(s,t);

    cout << getansw(s,t,0,0) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}