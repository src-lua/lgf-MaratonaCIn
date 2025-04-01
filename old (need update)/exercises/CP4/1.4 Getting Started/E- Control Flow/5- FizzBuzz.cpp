#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, n;

    cin >> a >> b >> n;

    for (int i = 1; i <= n; i++) {
        if (!(i % a) && !(i % b)) {
            cout << "FizzBuzz\n";
        } else if (!(i % a)) {
            cout << "Fizz\n";
        } else if (!(i % b)) {
            cout << "Buzz\n";
        } else {
            cout << i << '\n';
        }
    }

    return 0;
}