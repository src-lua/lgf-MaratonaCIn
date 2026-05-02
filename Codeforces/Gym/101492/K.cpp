/**
 * Author:      Lua
 * Problem:     K
 * Link:        https://codeforces.com/gym/101492/problem/K
 * Status:      ~
 * Created:     01-05-2026 09:34:33
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a = 1, b = 0;

    int k; cin >> k;

    for (int i = 0; i < k; i++) {
        b *= 2; b += 2;
    }
    cout << b + 1;  

    return 0;
}
