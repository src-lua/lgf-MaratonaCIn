#include <bits/stdc++.h>

#define endl '\n'
#define int long long 

using namespace std;
using ll = long long;

bool solve(int n, int k) {

    if (pow(2,n+1)-1 >= k) return true;
    else

    return false;
}

int binarySearch(int l, int r, int k)
{
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (!solve(m, k))
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    if (k == 1) {cout << 1; return 0;}

    int j = binarySearch(0,k, k);

    // cout << min(ll(pow(2,k+1)-1), n) - pow(2, j+1)-1;

    // 2^(k+1) - 2^(j+1) = 2^(j+1) * (2^(k-j) - 1)

    if (k < 64) {
        ll precalc = ll(pow(2, k)-1); 
        if (precalc < n) {
            cout << ll(pow(2, j) * (pow(2, k-j) - 1)) + (n-precalc);

        }    
        else
            cout << n - ll(pow(2, j)-1);

    }
    
    else
        cout << n - ll(pow(2, j)-1);

    return 0;
}