#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    while (a != 0 || b != 0) {
        if (a + b == 13) {
            cout << "Never speak again.\n";
        } 
        else if (a == b) {
            cout << "Undecided.\n";
        } 
        else if (a > b){
            cout << "To the convention.\n";
        }
        else if (a < b) {
            cout << "Left beehind.\n";
        } 

        cin >> a >> b;
    }

    return 0;
}