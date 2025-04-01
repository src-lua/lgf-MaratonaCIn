#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n; cin >> n;

    string s;

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == "#...") dq.push_front(1);
        else if (s == ".#..") dq.push_front(2);
        else if (s == "..#.") dq.push_front(3);
        else if (s == "...#") dq.push_front(4);
    }

    for (auto e : dq) {
        cout << e << ' ';
    }
    cout << endl;
    

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