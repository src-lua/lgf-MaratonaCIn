#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<double,double>;

const double PI = 3.1415926535;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(16) << fixed;

    int n; cin >> n;

    map<int, vector<pii>> m;
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        m[s].push_back({y,x});
    }

    double costheta = 0.9999997970867281; 
    double sintheta = 0.0006370451338896226;



    for (int _p = 0; _p < 1e4+1; _p++) {
        double mx = INFINITY;

        bool flag = true;

        for (auto &[_, v] : m) {
            for (int i = 0; i < v.size(); i++) {
                auto x = v[i].second,  y = v[i].first; 
                v[i].second = x*costheta - y*sintheta;
                v[i].first = x*sintheta + y*costheta;
            }
            mx = max_element(v.begin(), v.end()) ->first;
        }
        
        if (flag) {
            cout << "Y" << endl;
            return 0;
        }
    }
    
    cout << "N" << endl;
    return 0;
}