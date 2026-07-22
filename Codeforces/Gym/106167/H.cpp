/**
 * Author:      Lua
 * Problem:     H
 * Link:        https://codeforces.com/gym/106167/problem/H
 * Status:      ~
 * Tags:        
 * Created:     22-07-2026 08:28:05
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b; cin >> n >> a >> b;
    vector<int> A(a), B(b);

    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    reverse(B.begin(), B.end());

    vector<int> arr; arr.reserve(a+b);

    for (auto &x : A) arr.push_back(x);
    for (auto &x : B) arr.push_back(x);

    vector<int> pos(n+1);
    set<pair<int,int>> st;

    for (int i = 0; i < arr.size(); i++) {
        pos[arr[i]] = i;
        st.emplace(i, arr[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        auto it = st.find({pos[i], i});
        bool flag = false;
        
        it++;
        if(it != st.end() && it->second == 0) flag = true;
        it--; 
        if(!flag && it != st.begin()) {
            it--;
            if (it->second == 0) flag = true;
            it++;
        }

        st.erase(it);

        if (flag) ans++;
    }
    
    cout << ans << '\n';

    return 0;
}
