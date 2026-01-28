#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = 0;

    do {
        n++;

        cout << "Case " << n << ": ";

        if (s == "HELLO")
            cout << "ENGLISH\n";
        else if (s == "HOLA")
            cout << "SPANISH\n";
        else if (s == "HALLO")
            cout << "GERMAN\n";
        else if (s == "BONJOUR")
            cout << "FRENCH\n";
        else if (s == "CIAO")
            cout << "ITALIAN\n";
        else if (s == "ZDRAVSTVUJTE")
            cout << "RUSSIAN\n";
        else
            cout << "UNKNOWN\n";

        cin >> s;
    } while (s != "#");

    return 0;
}