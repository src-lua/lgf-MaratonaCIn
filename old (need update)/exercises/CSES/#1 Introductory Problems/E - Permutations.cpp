#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    if (n == 1) cout << '1' << endl;
    else if (n <= 3) cout << "NO SOLUTION" << endl;
    else {
        cout << (n+1)/2 << ' ';

        for (int i = 0; i < n/2; i++) {
            cout << n - i << ' ';
            if (n%2 == 1 || i != n/2 - 1) cout << i+1 << ' ';
        }
        
    }

    return 0;
}