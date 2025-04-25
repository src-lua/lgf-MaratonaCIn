#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> s, t;
    int x;
    long long int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            s.push_back(x);
            a += x;
        }
        else {
            t.push_back(-x);
            b -= x;
        }
    }

    if (a > b) cout << "first\n";
    else if (b > a) cout << "second\n";
    else {
        if (s > t) cout << "first\n";
        else if (t > s) cout << "second\n";
        else {
            if (x > 0) cout << "first\n";
            else cout << "second\n";
        }
    }

    return 0;
}