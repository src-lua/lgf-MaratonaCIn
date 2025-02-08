#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int arr[4] = {-1, -1, 3, 2};

    int x;
    for (int i = 0; i < n; i++) {
        cout << 1 << endl;

        cin >> x;

        cout << arr[x] << endl;

        cin >> x;
    }
    
    return 0;
}