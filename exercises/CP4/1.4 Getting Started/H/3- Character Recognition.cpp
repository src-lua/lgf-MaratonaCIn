#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; cin.get();
    string s1, s2, s3, s4, s5, s6;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    getline(cin, s4);
    getline(cin, s5);

    for (int i = 1; i <= n; i++) {
        if (s1[(i * 4)-1-1] == '.') cout << 1;
        else if (s4[(i * 4)-3-1] == '*') cout << 2;
        else if (s4[(i * 4)-1-1] == '*') cout << 3;
    } cout << endl;

    return 0;
}