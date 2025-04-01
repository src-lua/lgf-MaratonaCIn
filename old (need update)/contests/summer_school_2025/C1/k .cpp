#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> can(n-1); cin.get();
    char x;
    for (int i = 0; i < n-1; i++) {
        cin.get(x);
        can[i] = x-'0';
    }
    
    vector<int> fromleft(n-1);
    vector<int> fromright(n-1);
    int k = 0;
    for (int i = 0; i < n-1; i++) {
        fromleft[i] = k+1;
        if (can[i] == 0) {
            k = i+1;
        }
    }
    
    k = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (can[i] == 0) {
            k = i;
        }
        fromright[i] = k+1;
    }

    if (can.back() == 1) {
        fromleft.push_back(fromleft.back());
        fromright.push_back(arr.size());
    } else {
        fromleft.push_back(arr.size());
        fromright.push_back(arr.size());

    }

    for (int i = 0; i < n; i++) {
        if (!(fromleft[i] <= arr[i] && arr[i] <= fromright[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}