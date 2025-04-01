#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int g, s ,c; cin >> g >> s >> c;

    int power = 3*g + 2*s + 1*c;

    if (power >= 8) {
        cout << "Province or Gold\n";
    } else if (power >= 6) {
        cout << "Duchy or Gold\n";
    } else if (power >= 5) {
        cout << "Duchy or Silver\n";
    } else if (power >= 3) {
        cout << "Estate or Silver\n";
    } else if (power >= 2) {
        cout << "Estate or Copper\n";
    } else {
        cout << "Copper";
    }
    return 0;
}