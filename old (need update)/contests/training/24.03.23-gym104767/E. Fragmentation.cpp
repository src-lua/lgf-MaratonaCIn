#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int days; cin >> days;

    vector<int> arr(days);

    for (int i = 0; i < days; i++) {
        cin >> arr[i];
    }

    int q; cin >> q;

    for (int Q = 0; Q < q; Q++) {
        int l, r, target;
        cin >> l >> r >> target;

        int answ = 1;

            for (int i = l-1; i <= r-1; i++) {
            answ = (answ * arr[i]) % target;
            
            if (answ == 0) {
                cout << "Yes" << endl;
                break;
            }
        }

        if (answ != 0) {
            cout << "No" << endl;
        }        
    }

    return 0;
}