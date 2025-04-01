#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n ,w;
    cin >> k >> n >> w;

    cout << max(0, (k*(w*(1+w)/2)) - n) << endl;

    return 0;
}