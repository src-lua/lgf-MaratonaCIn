#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s;
    cin >> s;

    stack<int> st;
    int water = 0;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '/' && !st.empty()) {
            auto d = st.top(); st.pop();
            water += i-d;
        }
        else if (s[i] == '\\') {
            st.push(i);
        }
    }
    
    cout << water << endl;

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