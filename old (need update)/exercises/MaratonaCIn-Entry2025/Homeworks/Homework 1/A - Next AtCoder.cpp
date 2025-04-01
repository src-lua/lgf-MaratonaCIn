#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    cout << *(unique(arr.begin(), arr.end()) - 2) << '\n';

    return 0;
}