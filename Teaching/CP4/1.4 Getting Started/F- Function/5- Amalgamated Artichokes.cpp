#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int p, a, b, c, d;

double price(int k) { return p * (sin(a * k + b) + cos(c * k + d) + 2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    cin >> p >> a >> b >> c >> d;

    int n;
    cin >> n;

    double answ = 0;
    double maxPrice = price(1);
    double x;

    for (int i = 2; i <= n; i++) {
        x = price(i);

        answ = max(answ, maxPrice-x);
        maxPrice = max(maxPrice, x);
    }

    cout << answ << endl;

    return 0;
}