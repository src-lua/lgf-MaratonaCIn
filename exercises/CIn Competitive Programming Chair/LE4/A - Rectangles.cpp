#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int answ = 0;

    int i = 1;
    while (n/i) {
        if (!(n%i)) answ += max(i, n/i);
        i++;
    }

    cout << answ << endl;

    // 2 * 3 == 6 

    return 0;
}