#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int x;
    int c = 0;
    int k = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) {
            c += x;
            k++;
        }
    }

    cout  << setprecision(6) << (double) c / k << endl;

    return 0;
}