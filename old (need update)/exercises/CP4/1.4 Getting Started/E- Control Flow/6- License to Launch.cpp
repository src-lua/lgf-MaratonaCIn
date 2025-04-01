#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int minvalue = INT_MAX;
    int minindex = 0;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (minvalue > x) {
            minvalue = x;
            minindex = i;
        }
    }

    cout << minindex << '\n';

    return 0;
}