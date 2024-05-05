#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s;
    for (int i = 0; i <= n; i++) {
        s += to_string(i);
    }

    int c = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4' && s[i+1] == '2') {
            c++;
        }
    }

    cout << c;

    return 0;
}