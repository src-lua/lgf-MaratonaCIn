#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> toy(n);
    vector<int> box(n-1);

    for (int i = 0; i < n  ; i++) cin >> toy[i];
    for (int i = 0; i < n-1; i++) cin >> box[i];
    
    sort(toy.rbegin(), toy.rend());
    sort(box.rbegin(), box.rend());

    int answ = -1;

    for (int i = 0; i < n-1; i++) {
        if (toy[i] > box[i]) {
            box.push_back(toy[i]);
            answ = toy[i];
            break;
        }
    }

    if (answ == -1) answ = toy[n-1];
    else {
        sort(box.rbegin(), box.rend());
        for (int i = 0; i < n; i++) {
            if (toy[i] > box[i]) {
                answ = -1;
                break;
            }
        }
    }

    cout << answ << '\n';

    return 0;
}