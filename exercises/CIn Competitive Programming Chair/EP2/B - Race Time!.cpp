#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define double long double

vector<double> arrS(1e6 + 1);
vector<double> arrD(1e6 + 1);
int N;

double f(double T) {
    double arr_min = arrS[0]*T+arrD[0];
    double arr_max = arr_min;

    for (int i = 1; i < N; i++) {
        arr_min = min(arr_min, arrS[i]*T+arrD[i]);    
        arr_max = max(arr_max, arrS[i]*T+arrD[i]);
    }

    return arr_max - arr_min;
}

double gss(double a, double b) {
    const double r = (sqrt(5)-1)/2, eps = 1e-9;
    
    double x1 = b - r*(b-a),
           x2 = a + r*(b-a);
    double f1 = f(x1),
           f2 = f(x2);
    
    for(int it = 0; it < 1000 && b-a > eps; it++)
        if (f1 < f2) { //change to > to find maximum
            b = x2; x2 = x1; f2 = f1;
            x1 = b - r*(b-a); f1 = f(x1);
        } 
        else {
            a = x1; x1 = x2; f1 = f2;
            x2 = a + r*(b-a); f2 = f(x2);
        }
    return b;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(7) <<  fixed;

    double k;
    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        cin >> arrS[i] >> arrD[i];
    }
        cout << f(gss(0, k+1)) << endl;

    return 0;
}
