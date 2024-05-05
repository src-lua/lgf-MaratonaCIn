#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const ll INF = LLONG_MAX;
const int MXN = 1005;
int v,e;
int n, m;
vector<vector<ll>> dist(MXN, vector<ll>(MXN, INF));
vector<vector<int>> board(MXN, vector<int>(MXN));
vector<vector<ll>> horizontal(MXN, vector<ll>(MXN));
vector<vector<ll>> vertical(MXN, vector<ll>(MXN));

void dfs(){
	queue<pii> q;
    dist[n-1][m-1] = 0;
	q.push({n-1, m-1});
	while(!q.empty()) {
		auto [a,b] = q.front();
		q.pop();

        if (a>0) {
            if (dist[a][b]+vertical[a-1][b]*vertical[a-1][b] < dist[a-1][b]) {
                dist[a-1][b] = dist[a][b]+vertical[a-1][b]*vertical[a-1][b];
                q.push({a-1,b});
            }
        }
        if (b>0) {
            if (dist[a][b]+horizontal[a][b-1]*horizontal[a][b-1] < dist[a][b-1]) {
                dist[a][b-1] = dist[a][b]+horizontal[a][b-1]*horizontal[a][b-1];
                q.push({a,b-1});
            }
        }

	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            horizontal[i][j] = horizontal[i][j-1] + board[i][j-1];
        }
        
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            vertical[j][i] = vertical[j-1][i] + board[j-1][i];
        }
    }
    
    dfs();
    
    cout << dist[0][0];

}
