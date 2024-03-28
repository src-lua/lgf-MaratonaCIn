#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int bin[30] = {11111, 11110, 11101, 11100, 11011, 11010, 11001, 11000, 10111, 10110, 10101, 10100, 10011, 10010, 10001, 10000, 1111, 1110, 1101, 1100, 1011, 1010, 1001, 1000, 111, 110, 101, 100, 11, 10};

int solve() {

    int n; cin >> n;

    for (int i = 0; i < 30; i++) {
        while (n%bin[i] == 0) {
            n /= bin[i];
        }

        if (n == 1) break;
    }

    if (n == 1) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}