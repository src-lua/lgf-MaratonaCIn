#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> s;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.emplace(x);
    }

    cout << s.size() << '\n';
    

    return 0;
}