#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;
using pii = pair<int,int>;
using iii = tuple<int,int,int>;

int r, c;

bool cmp(int n, pair<int, int> const& p)
{
    return ((p.first < n) && (p.second < n));
}

int ss (int idx, vector<int>& arr, vector<map<int, vector<pii>>>& numbers, int i, int j) {
    if (idx >= arr.size()) return idx;

    auto e = arr[idx];

    int answ = idx-1;

    for (int k = r+c-2; k >= 0; k--) {
        if (numbers[k].count(e) != 0) {
            for (auto [curr_i, curr_j] : numbers[k][e]) {
                if (i < curr_i || j < curr_j) continue;
                answ = max(answ, ss(idx+1, arr, numbers, curr_i, curr_j));
            }
            break;
        }
    }
    
    return answ;
}

int solve() {

    int n; cin >> n >> r >> c;

    vector<int> arr(n);
    vector<vector<int>> matrix(r,vector<int>(c));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    // map<int,vector<iii>> numbers;
    vector<map<int, vector<pii>>> numbers(r+c-1);

    for (int s = 0; s < 2*max(r,c)-1; s++) {
        for (int i = 0; i < r && i <= s; i++) {
            int j = s-i;

            if (j >= c) continue;

            numbers[s][matrix[i][j]].push_back({i, j});
        }
    }

    cout << ss(0, arr, numbers, 0, 0) << endl;

    


    

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