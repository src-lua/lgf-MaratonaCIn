#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ceil, floor;
    ceil.push_back(INT_MAX), floor.push_back(INT_MIN);

    for (int i = 1; i < n; i++) {
        auto e = arr[i];
        if (e < floor.back() || e > ceil.back()) {
            cout << "yes\n";
            return 0;
        }
        
             if (e > arr[i-1]) floor.push_back(arr[i-1]);
        else if (e < arr[i-1]) ceil.push_back(arr[i-1]);
        
        if (e == floor.back()) floor.pop_back();
        if (e == ceil.back()) ceil.pop_back();
        
        // if (e == arr[i+1] && i+1 < n) {
        //     cout << "yes\n";
        //     return 0;
        // } 
    }
    
    cout << "no\n";
    return 0;
}