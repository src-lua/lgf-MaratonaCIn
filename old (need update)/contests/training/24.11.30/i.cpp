#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve(int i, vector<int>& arr, int intelligence, int strengt, int points, int answ) {
    if (i == arr.size()) return answ;

    if (arr[i] == 0) return solve(i+1, arr, intelligence, strengt, points+1, answ);
    if (arr[i] > 0) { // Intelligence check
        if (intelligence >= abs(arr[i])) return
            solve(i+1, arr, intelligence, strengt, points, answ+1);

        if (points+intelligence >= abs(arr[i])) return max(
            solve(i+1, arr, abs(arr[i]), strengt, points - (abs(arr[i]) - intelligence), answ+1),

            solve(i+1, arr, intelligence, strengt, points, answ)
        );
        
        return solve(i+1, arr, intelligence, strengt, points, answ);
    }

    if (arr[i] < 0) { // Strengt check
        if (strengt >= abs(arr[i])) return
            solve(i+1, arr, intelligence, strengt, points, answ+1);

        if (points+strengt >= abs(arr[i])) return max(
            solve(i+1, arr, intelligence, abs(arr[i]), points - (abs(arr[i]) - strengt), answ+1),

            solve(i+1, arr, intelligence, strengt, points, answ)
        );

        return solve(i+1, arr, intelligence, strengt, points, answ);
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int mx; cin >> mx;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << solve(0, arr, 0, 0, 0, 0) << '\n';

    return 0;
}