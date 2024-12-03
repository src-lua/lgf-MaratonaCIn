#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr.begin(), arr.end());

    if ((arr[0] + arr[1] + arr[2]) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << arr [0] + abs(min(arr[0]+arr[1], arr[2]) - arr[2])/2 << endl;
    

    return 0;
}