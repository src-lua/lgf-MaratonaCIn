#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char x, y, z;

    cin >> x >> y >> z;

    if (x == '<' && y == '<'  && z == '<') cout << 'B' << endl; else
    if (x == '<' && y == '<'  && z == '>') cout << 'C' << endl; else
    if (x == '<' && y == '>'  && z == '<') cout << 'A' << endl; else
    if (x == '<' && y == '>'  && z == '>') cout << 'A' << endl; else
    if (x == '>' && y == '<'  && z == '<') cout << 'A' << endl; else
    if (x == '>' && y == '<'  && z == '>') cout << 'X' << endl; else
    if (x == '>' && y == '>'  && z == '<') cout << 'C' << endl; else
    if (x == '>' && y == '>'  && z == '>') cout << 'B' << endl;

    return 0;
}