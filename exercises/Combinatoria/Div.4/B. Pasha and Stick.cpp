#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve(int n) {

    if (n % 2 == 1) return 0;

    int k = (((n-2)/2) - 1);
    if (k % 2 == 1) k+= 1;
     
    return k / 2; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    cout << solve(n) << '\n'; 

    return 0;
}