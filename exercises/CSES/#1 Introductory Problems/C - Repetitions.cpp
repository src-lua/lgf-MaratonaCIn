#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int answ = 0;
    int c = 1;
    char prev = ' ';


    for (auto e : s) {
        if (e == prev) c++;
        else {
            answ = max(answ, c);
            c = 1;
        }

        prev = e; 
    }

    answ = max(answ, c);

    cout << answ << endl;

    return 0;
}