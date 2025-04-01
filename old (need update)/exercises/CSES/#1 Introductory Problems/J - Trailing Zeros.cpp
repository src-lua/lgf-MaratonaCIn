#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    ll answ = 0;

    for (int i = 1; pow(5,i) < 1e9; i++) {
        answ += n/pow(5, i);
    }

    cout << answ << endl;

    return 0;
}