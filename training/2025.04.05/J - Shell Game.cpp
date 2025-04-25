#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int a, b; 
    
    cin >> a >> b;
    if (a == n) n = b;
    else if (b == n) n = a;
    
    cin >> a >> b; 
    if (a == n) n = b;
    else if (b == n) n = a;
    
    
    cin >> a >> b; 
    if (a == n) n = b;
    else if (b == n) n = a;

    cout << n;

    return 0;
}