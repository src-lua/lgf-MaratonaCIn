#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int group(int a, int n) {
    return (int) ceil(float(a)/float(n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;

    int c;
    int answ;

    while(cin >> n >> a >> b) {
        c = n;
        n = 1 << n;
        while (1) {
            if (group(a, n) == group(b,n)) {
                answ = c--;
                n/=2;
            } else {
                cout << answ << endl;
                break;
            }
        }
        
        
    }

    return 0;
}