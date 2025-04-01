#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >>k;

    for (int x = 1; x <= k; x++) {
        cout << a * x + b << ' ';
    }
    

    return 0;
}