#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> lll;
typedef tuple<int,int,int> iii;

#define endll '\n';

int INF = INT_MAX;
long long INFF = LLONG_MAX;
int dx[8] = { -1, 0, 0, 1, 0, -1, 1, 1 };
int dy[8] = { 0, 1, -1, 0, 0, 1, -1, 1 };

#define FOR(i,L,R) for (int i = L; i < R; i++)

#define ALL(c) (c).begin(),(c).end()


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> board(n, vector<int>(m, 0));

    int a, b, c;
    int bombs;

    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        board[--a][--b] = c;
        bombs+=c;
    }

    int max = 0;
    int act = 0;
    pii max_idx = {0,0};
	int answ = 0;

    while(bombs) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0) {
                    max = 0;
                    for (int d = 0; d < 5; d++) {
                        if (i+dx[d] < n && i+dx[d]>= 0 && j+dy[d] < m && j+dy[d] >= 0) {
			            act = 0;
                            for (int d2 = 0; d2 < 5; d2++) {
                                if (i+dx[d]+dx[d2] < n && i+dx[d]+dx[d2]>= 0 && j+dy[d]+dy[d2] < m && j+dy[d]+dy[d2] >= 0) {
                                    act += board[i+dx[d]+dx[d2]][j+dy[d]+dy[d2]];
                                    }
                                }
                            if (act > max) {
                                max = act;
                                max_idx = {i+dx[d], j+dy[d]};
                            }
                        }
                    }
                    
                    int minv = INF;

                    for (int d = 0; d < 5; d++) {
                        if (max_idx.first+dx[d] < n && max_idx.first+dx[d]>= 0 && max_idx.second+dy[d] < m && max_idx.second+dy[d] >= 0 && board[max_idx.first+dx[d]][max_idx.second+dy[d]]!=0) {
                            minv = min(minv, board[max_idx.first+dx[d]][max_idx.second+dy[d]]); 
                        }
                    }
    
                    for (int d = 0; d < 5; d++) {
                        if (max_idx.first+dx[d] < n && max_idx.first+dx[d]>= 0 && max_idx.second+dy[d] < m && max_idx.second+dy[d] >= 0 && board[max_idx.first+dx[d]][max_idx.second+dy[d]]!=0) {
                            board[max_idx.first+dx[d]][max_idx.second+dy[d]] -= minv;
                            bombs -= minv;
                        }
                    }

                    answ += minv;

                }
            }
            
        }
        
    }
    cout << answ;
    

}