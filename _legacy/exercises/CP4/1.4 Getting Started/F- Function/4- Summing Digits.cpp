#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x;
    cin >> x;

    while (x != 0) {
        while(x>=10) {
            long long temp = 0;
            while (x > 0) {
                temp += x % 10;
                x /= 10;
            }
            x = temp;
        }

        cout << x << endl;

        cin >> x;
    }

    return 0;
}