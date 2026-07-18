/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[Crumbu Conundrum](https://codeforces.com/gym/105741/problem/E)
Rating: NOT DEFINED
Tags: Implementation; BFS; Grid; Probability;

Date: 2025-03-29
Status: Accepted during contest
*/


#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs(vector<vector<char>>& adj, vector<vector<int>>& pos, vector<pii>& start) {
    queue<pii> operation_order;

    for (auto [x,y] : start) {
        pos[x][y] = 0;
        operation_order.push({x,y});
    }

    while (!operation_order.empty()) {
        auto [x,y] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            int i = x + dx[d], j = y + dy[d];

            if (i < 0 || i >= adj.size() || j < 0 || j >= adj.size()) continue;
            if (adj[i][j] != '.') continue;
            if (pos[i][j] == INT_MAX) {
                pos[i][j] = pos[x][y] + 1;
                operation_order.push({i,j});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    int n, q; cin >> n >> q;
    char c;
    int empty = 0;
    vector<vector<char>> board(n, vector<char>(n));
    vector<pii> entrances;
    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < n; j++) {
            cin.get(c);
            board[i][j] = c;
            if (c == 'E') entrances.push_back({i,j});
            else if (c == '.') empty++;
        }
    }
    
    vector<vector<int>> pos(n, vector<int>(n, INT_MAX));
    bfs(board, pos, entrances);

    map<int,int> freqs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') continue;
            freqs[pos[i][j]]++;
        }    
    }

    vector<int> vals;
    vector<int> freq;

    for (auto [k, v] : freqs) {
        vals.push_back(k);
        freq.push_back(v);
    }

    vector<int> prefix(freq.size()+1);
    prefix[0] = 0;

    for (int i = 0; i < freq.size(); i++) {
        prefix[i+1] = prefix[i] + freq[i];
    }
    

    int x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin(); 
        cout << ((double(prefix[idx])) / (double(empty))) << '\n';
    }
    


    

    return 0;
}