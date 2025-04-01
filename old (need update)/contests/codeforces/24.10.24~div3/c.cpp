#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int get_answ(vector<int>& arr, int c, int idx) {
    if (idx >= arr.size()/2) return c;

    int swap_idx = arr.size()-idx-1;

    if ((idx < arr.size()-1 && arr[idx] == arr[idx+1]) || (idx > 0  && arr[idx] == arr[idx-1])
    || (swap_idx < arr.size()-1 && arr[swap_idx] == arr[swap_idx+1]) || (swap_idx > 0  && arr[swap_idx] == arr[swap_idx-1])
    ) {
        if (arr[idx] != arr[swap_idx]) {
            int a = get_answ(arr, c, idx+1);

            if (idx < arr.size()-1 && arr[idx] == arr[idx+1]) c--;
            if (idx > 0  && arr[idx] == arr[idx-1]) c--;

            if (swap_idx < arr.size()-1 && arr[swap_idx] == arr[swap_idx+1]) c--;
            if (swap_idx > 0  && arr[swap_idx] == arr[swap_idx-1]) c--;

            swap(arr[idx], arr[swap_idx]);

            if (idx < arr.size()-1 && arr[idx] == arr[idx+1]) c++;
            if (idx > 0  && arr[idx] == arr[idx-1]) c++;

            if (swap_idx < arr.size()-1 && arr[swap_idx] == arr[swap_idx+1]) c++;
            if (swap_idx > 0  && arr[swap_idx] == arr[swap_idx-1]) c++;

            int b = get_answ(arr, c, idx+1);

            swap(arr[idx], arr[swap_idx]);

            return min(a, b);
        }
    }

    return get_answ(arr, c, idx+1);

}

int solve() {

    int n; cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int c = 0;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) c++;
    }
    
    cout << get_answ(arr, c, 0) << '\n';

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