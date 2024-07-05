#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    if (v[1] - v[0] == v[2] - v[1]) {
        cout << v[2] + v[2] - v[1] << endl;
    } else if (v[1] - v[0] > v[2] - v[1]) {
        cout << v[0] + v[2] - v[1] << endl;
    } else {
        cout << v[1] + v[1] - v[0] << endl;
    }

    return 0;
}