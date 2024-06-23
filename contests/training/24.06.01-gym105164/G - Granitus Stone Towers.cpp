#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);

    int x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answ = 0;
    int c = 0;
    
    if (a[0] == 1) {
        for (auto e: a) {
            if (e == ++c) {
                answ++;
            }
            else if (e == c-1) { c--; }
            else break;
        }

    }

    if (answ %2 == 0) {
        cout << "Alicius\n";
    } else {
        cout << "Bobius\n";
    }
    
    

    return 0;
}