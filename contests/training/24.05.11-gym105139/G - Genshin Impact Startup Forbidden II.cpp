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
int dx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int dy[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define FOR(i,L,R) for (int i = L; i < R; i++)

#define ALL(c) (c).begin(),(c).end()

vector<vector<char>> board(19, vector<char>(19, '#'));
vector<vector<bool>> visited(19, vector<bool>(19, false));



void reset_visited() {
    //visited.resize(19, vector<bool>(19, false)
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            visited[i][j] = false;
        }   
    }
}

int bfs(pii cord, char target) {
    
    queue<pii> operation_order;
    operation_order.push(cord);

    visited[cord.first][cord.second] = true;

    int answ = 1;
    int i, j;
    bool flag = false;

    while(!operation_order.empty()) {
        auto [x,y] = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            if (x+dx[d] < 19 && x+dx[d]>= 0 && y+dy[d] < 19 && y+dy[d] >= 0) {
                i = x+dx[d]; j = y+dy[d];

                if (visited[i][j]) continue;

                if (board[i][j] == target) {
                    answ++;
                    visited[i][j] = true;
                    operation_order.push({i,j});
                }
                else if (board[i][j] == '#') return 0;
            }
        }
    }

    return answ;
    
}

void remove() {
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (visited[i][j]) board[i][j] = '#';
        }   
    }
    
}

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int tc; cin >> tc;
 
    int answ; int out; int answ2;
 
    int a, b, x, y;
 
    for (int i = 1; i <= tc; i++) {
        if (i%2==1) { // Black move
            cin >> a >> b;
            board[--a][--b] = 'B';
 
            answ = 0;
            reset_visited();
            for (int d = 0; d < 4; d++) {
                x = a+dx[d]; y = b+dy[d];
                if (!(x < 19 && x>= 0 && y < 19 && y>= 0))  continue;
                if (board[x][y] == '#' or board[x][y] == 'B') continue;

                reset_visited();
                out = bfs({x,y}, 'W');
 
                if (out) {
                    answ += out;
                    remove();
                }
            }
            
            if (!answ) {
                reset_visited();
                answ2 = bfs({a,b}, 'B');
                
                if (answ2) {
                    remove();
                }
                
            } else answ2 = 0;
            
            cout << answ2 << " " << answ << '\n';
            
        }
        else { // White move
            cin >> a >> b;
            board[--a][--b] = 'W';
 
            answ = 0;
            reset_visited();
            for (int d = 0; d < 4; d++) {
                x = a+dx[d]; y = b+dy[d];
                if (!(x < 19 && x>= 0 && y < 19 && y>= 0))  continue;
                if (board[x][y] == '#' or board[x][y] == 'W') continue;

                reset_visited();
                out = bfs({x,y}, 'B');
 
                if (out) {
                    answ += out;
                    remove();
                }
            }
            
            if (!answ) {
                reset_visited();
                answ2 = bfs({a,b}, 'W');
                
                if (answ2) {
                    remove();
                }
                
            } else answ2 = 0;
            
            cout << answ << " " << answ2 << '\n';
            
        }
    }
    
 
}