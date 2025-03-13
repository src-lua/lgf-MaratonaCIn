#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<string> solve(int n) {

    if (n == 1) return {"0", "1"}; // 00 01 11 10

    vector<string> answ;

    auto a = solve(n-1);
    
    for (auto e : a) {
        answ.push_back('0'+e);
    }

    for (int i = a.size()-1; i >= 0; i--) {
        answ.push_back('1' + a[i]); 
    }
    
    return answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    auto k = solve(n);

    for (auto e : k) cout << e << '\n';

    return 0;
}