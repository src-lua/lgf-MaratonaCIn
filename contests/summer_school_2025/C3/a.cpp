#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

struct Point {
    ll x;
    ll y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, r;
    cin >> x >> y >> r;

    Point a, b, c, d;
    a = {x+r, y+r};
    b = {x-r, y+r};
    c = {x-r, y-r};
    d = {x+r, y-r};

    cout << a.x << ' ' << a.y << endl; 
    cout << b.x << ' ' << b.y << endl; 
    cout << c.x << ' ' << c.y << endl; 
    cout << d.x << ' ' << d.y << endl; 

    return 0;
}