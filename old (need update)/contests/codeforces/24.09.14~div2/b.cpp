#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int binarySearchL(int l, int r, vector<int>& arr, int target) { 
    int answ = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (! (arr[m] > target) )
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            r = m - 1;
            answ = m;
        }
    }
    if (answ == -1) answ = r+1;

    return answ;
}

int binarySearchR(int l, int r, vector<int>& arr, int target) { 
    int answ = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (arr[m] < target) {
            l = m + 1;
            answ = m;
        }
        // If SOLVE, ignore right half
        else {
             r = m - 1;
        }
    }

    if (answ == -1) answ = l-1;

    return answ + 1;
}

int solve() {

    int n, m, q; cin >> n >> m >> q;

    vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int k;
    for (int i = 0; i < q; i++) {
        cin >> k;
        
        int lpos = binarySearchL(0, arr.size()-1, arr, k)-1;
        int rpos = binarySearchR(0, arr.size()-1, arr, k);

        int answ;

        if (lpos == -1) answ = arr[rpos] - 1;
        else if (rpos == arr.size()) answ = n - arr[lpos]; 
        else answ = (arr[rpos] - arr[lpos]) / 2; 

        cout << answ << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}