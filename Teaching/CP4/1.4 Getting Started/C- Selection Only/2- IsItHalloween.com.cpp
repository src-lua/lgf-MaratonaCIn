#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n; cin >> n;

    if ((s == "OCT" && n == 31) || (s == "DEC" && n == 25)) {
        cout << "yup";
        return 0;
    }

    cout << "nope";
    return 0;
}