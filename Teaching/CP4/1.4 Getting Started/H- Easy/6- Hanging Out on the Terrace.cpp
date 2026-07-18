#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, n; cin >> l >> n;

    int c = 0;

    string s;
    int x;

    int k = 0;

    for (int i = 0; i < n; i++) {
        cin >> s >> x;

        if (s == "enter") {
            if (c + x <= l) {
                c += x;
            } else {
                k++;
            }
        } else {
            c-=x;
        }
    }
    
    cout << k << endl;

    return 0;
}