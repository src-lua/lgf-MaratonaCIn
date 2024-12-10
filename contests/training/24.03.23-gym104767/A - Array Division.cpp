#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

bool solve(vector<int>& arr, int target_sum, int k) {
    ll current_sum = 0;
    int divisions = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        if (current_sum + arr[i] > target_sum) {
            current_sum = arr[i];
            divisions++;
        } else current_sum += arr[i];
    }
    

    return divisions <= k;
}

// Time Complexity: O(log(n))
int binarySearch(int l, int r, vector<int>& arr, int k) {
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (solve(arr, m, k)) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << binarySearch(0, INT_MAX, arr, k) << endl;

    return 0;
}