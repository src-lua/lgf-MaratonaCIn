#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

double fexp(double a, int b) {
    double res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(12) << fixed;

    int n, q; cin >> n >> q;
    double r; cin >> r;

    vector<int> day(n);
    vector<int> material(n);
    vector<double> waste(n+1);
    
    vector<pair<int,int>> entry(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        entry[i] = {a,b};
    }

    sort(entry.begin(), entry.end());

    {
        day[0] = entry[0].first;
        material[0] = entry[0].second;
        waste[1] = r*material[0];
    }
    for (int i = 1; i < n; i++) {
        day[i] = entry[i].first;
        material[i] = entry[i].second;
        waste[i+1] = waste[i] * fexp((1-r), day[i]-day[i-1]) + r * material[i];
    }

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        int l = upper_bound(day.begin(), day.end(), x) - day.begin();

        cout << waste[l] * fexp((1-r),abs(day[l-1]-x)) << endl;
    }

    return 0;
}