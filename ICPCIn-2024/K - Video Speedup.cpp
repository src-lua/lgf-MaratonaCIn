#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(10) << fixed;

    int n, p, k; cin >> n >> p >> k;

    double answ = 0;
    int prev_time = 0;
    int x;
    int dur;

    for (int i = 0; i < n; i++){
        cin >> x;

        dur = x-prev_time;
        
        answ += dur * (double(100 + i*p)/100);

        prev_time = x;
    }

    dur = k - prev_time;

    answ += dur * (double(100 + n*p)/100);
    
    cout << answ;

    return 0;
}