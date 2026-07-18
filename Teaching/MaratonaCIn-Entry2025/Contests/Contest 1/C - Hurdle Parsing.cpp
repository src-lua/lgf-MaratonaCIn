#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    vector<int> arr;
    int c = 0;

    for (auto e : s) {
        if (e == '|') {
            arr.push_back(c);
            c = 0;
        }
        else c++;
    }

    for (int i = 1; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    } cout << '\n';
    

    return 0;
}