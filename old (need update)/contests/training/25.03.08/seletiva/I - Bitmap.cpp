#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

// Time Complexity: O(V + E)
void bfs(vector<vector<int>>& answ, vector<pii>& start) {
    queue<pii> operation_order;

    for (auto [i,j] : start) {
        answ[i][j] = 0;
        operation_order.push({i,j});
    }

    while (!operation_order.empty()) {
        auto [i,j] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            int x = i+dx[d], y = j+dy[d];
            
            if (x < 0 || y < 0 || x >= answ.size() || y >= answ[0].size()) continue;

            if (answ[x][y] == -1) {
                answ[x][y] = answ[i][j] + 1;
                operation_order.push({x,y});
            }
        }        
    }
}

int solve() {

    int row, col; char c;
    
    cin >> row >> col;
    
    vector<pii> start;

    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(c);
            if (c=='1') {
                start.push_back({i,j});
            }
        }
    }

    vector<vector<int>> answ(row, vector<int>(col, -1));

    bfs(answ, start);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << answ[i][j] << ' ';
        }
        cout << endl;
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