#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

struct Cord {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(12) << fixed;

    int n; double k;
    cin >> n >> k;

    vector<Cord> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;

    double maxHeight = arr[0].y;

    for (int i = 0; i < n-1; i++) {
        auto [x1, y1] = arr[i];
        auto [x2, y2] = arr[i+1];

        ll w = x2 - x1, h = y2 - y1;

        double d = sqrt(w*w + h*h);

        if (d <= k) {
            k -= d;
            maxHeight = max(maxHeight, max(double(y1), double(y2)));
        }
        else {
            double tg = double(h)/double(w);
            if (tg > 0) {
                double sn = sin(atan(tg));

                auto co = sn * k;
                maxHeight = max(maxHeight, double(y1)+co);
            }
            break;
        }
    }
    
    cout << maxHeight << endl;

    return 0;
}