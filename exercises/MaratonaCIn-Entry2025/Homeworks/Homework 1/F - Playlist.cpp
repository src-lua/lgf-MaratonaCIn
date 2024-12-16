#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    map<int, int> rep;

    int answ = 0;
    int bound = 0;

    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (rep[x] != 0) bound = max(rep[x], bound);
        answ = max(i-bound, answ);
        rep[x] = i;
    }

    cout << answ << endl;

    return 0;
}