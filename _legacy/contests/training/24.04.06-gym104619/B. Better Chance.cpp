#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(15) << fixed;

    int rt, rj; cin >> rt >> rj;
    double st, sj; cin >> st >> sj;

    double taoyuan = (rt-1) / st;
    double jakarta = (rj-1) / sj;

    if (abs(taoyuan - jakarta) < 10e-11) {
        cout << "SAME";
    }

    else if (taoyuan < jakarta) {
        cout << "TAOYUAN";
    }

    else if (jakarta < taoyuan) {
        cout << "JAKARTA";
    }




    return 0;
}