#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int target, x;

    cin >> target;

    for (int i = 2; i <= n; i++) {
        cin >> x;

        if (x > target) {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;
    return 0;
}