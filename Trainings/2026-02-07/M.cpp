/**
 * Author:      Lua
 * Problem:     M - Restore Points
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101498/problem/M
 * Status:      ~
 * Created:     07-02-2026 08:44:50
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int m = n*(n-1)/2;

    multiset<int> heap;

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        heap.insert(x);
    }

    vector<int> ans;
    multiset<int> not_ans;
    
    while(!heap.empty()) {
        int top = *heap.rbegin();
        heap.erase(--heap.end());

        vector<multiset<int>::iterator> fnds, fnds2;
        for (auto e : ans) {
            auto f = heap.find(abs(top-e));
            if (f != heap.end()) fnds.push_back(f); 
            else {
                auto f2 = not_ans.find(abs(top-e));
                if (f2 != not_ans.end()) fnds2.push_back(f2);
            }
        }

        if (fnds.size() + fnds2.size() != ans.size()) not_ans.insert(top);
        else {
            for (auto e : fnds) heap.erase(e);
            for (auto e : fnds2) not_ans.erase(e);

            ans.push_back(top);
        }
    }

    sort(ans.begin(), ans.end());
    cout << '0'; 
    for (auto const & e : ans) cout << ' ' << e; 
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; while(tc--) solve();

    return 0;
}
