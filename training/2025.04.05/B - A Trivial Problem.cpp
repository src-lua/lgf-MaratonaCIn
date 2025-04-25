#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int c = 0;
    for (int j = 5; c < n; j+=5) {
        int i = j;
        c = 0;
        while(i/5) {
            c += i /= 5;
        }
        if (c == n) {
            cout << 5 << '\n';
            cout << j  << ' ' << j+1 << ' ' << j+2 << ' ' << j+3 << ' ' << j+4 << '\n';
            return 0;
        }

    }
    
    cout << 0 << '\n';
    return 0;
}