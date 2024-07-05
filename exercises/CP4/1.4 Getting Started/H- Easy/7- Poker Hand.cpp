#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    map<char, int> m;

    for (int i = 0; i < 5; i++) {
        cin >> s;
        m[s[0]]++;
    }

    int maxv = 0;

    for (auto e : m) {
        maxv = max(maxv, e.second);
    }

    cout << maxv << endl;
    
    return 0;
}