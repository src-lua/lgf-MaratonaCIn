#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int answ = 0;

    for (int i = 1; i <= 12; i++) {
        cin >> s;
        if (s.size() == i) answ ++;
    }
    
    cout << answ << endl;

    return 0;
}