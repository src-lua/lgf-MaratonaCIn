#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int d;

double f (double x) {
    return x + d/(x+1);
}   

double gss(double a, double b) {
    const double r = (sqrt(5)-1)/2, eps = 1e-7;
    double x1 = b - r*(b-a), x2 = a + r*(b-a);
    double f1 = f(x1), f2 = f(x2);
    for(int it = 0; it < 250 && b-a > eps; it++)
        if (f1 < f2) { //change to > to find maximum
        b = x2; x2 = x1; f2 = f1;
        x1 = b - r*(b-a); f1 = f(x1);
        } else {
        a = x1; x1 = x2; f1 = f2;
        x2 = a + r*(b-a); f2 = f(x2);
        }
    return a;
}

int solve() {
    
    int n;
    
    cin >> n >> d;

    if (n >= d || f(gss(0,n)) - n <= 1e-8) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}