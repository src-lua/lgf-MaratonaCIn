#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool solve(int m, vector<int>& arr) {

    int c = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= m) {
            c++;
            if (c >= m) return true;
        }
        else {
            c = 0;
        }
    }

    return false;
}

// Time Complexity: O(log(n))
int binarySearch(int l, int r, vector<int>& arr) {
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if ((solve(m, arr)) )
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

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << binarySearch(0, INT_MAX, arr) << '\n';
    
    return 0;
}