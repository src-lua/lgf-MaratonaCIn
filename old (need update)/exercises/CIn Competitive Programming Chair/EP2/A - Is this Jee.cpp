#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

double b, c;

double f(double x) {

    return double( pow(x,2) + b*x + c ) / sin( x );

}

double gss(double a_lim, double b_lim) {
  const double r = (sqrt(5)-1)/2, eps = 1e-7;
  double x1 = b_lim - r*(b_lim-a_lim), x2 = a_lim + r*(b_lim-a_lim);
  double f1 = f(x1), f2 = f(x2);
  for(int it = 0; it < 300 && b_lim-a_lim > eps; it++)
    if (f1 < f2) { //cha_limnge to > to find ma_limximum
      b_lim = x2; x2 = x1; f2 = f1;
      x1 = b_lim - r*(b_lim-a_lim); f1 = f(x1);
    } else {
      a_lim = x1; x1 = x2; f1 = f2;
      x2 = a_lim + r*(b_lim-a_lim); f2 = f(x2);
    }
  return a_lim;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(10) << fixed;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b >> c;

        cout << f(gss(0, M_PI/2.f)) << endl ;
    }
    
    return 0;
}
