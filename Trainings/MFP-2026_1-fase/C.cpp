/**
 * Author:      Lua
 * Problem:     C
 * Link:        https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/C
 * Status:      AC
 * Created:     07-05-2026 19:05:05
 **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b; cin >> a >> b;

    set<int> divisors;
    for (int i = 1; i*i <= a; i++) {
        if (a%i == 0) divisors.insert(i), divisors.insert(a/i);
    }
    
    for (auto &x : divisors) {
        if (x >= a-b) {
            cout << x << '\n';
            return 0;
        }
    }

    return 0;
}
