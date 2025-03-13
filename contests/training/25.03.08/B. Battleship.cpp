#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int dx[] = {0, 0, 1,-1, 1, 1,-1,-1};
const int dy[] = {1,-1, 0, 0, 1,-1, 1,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<char>> board(10, vector<char>(10));
    vector<vector<bool>> visited(10, vector<bool>(10, false));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> ships(5, 0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == '#' && !visited[i][j]) {
                visited[i][j] = true;
                int c = 0;
                int dir = -1;
                for (int d = 0; d < 8; d++) {
                    int x = i+dx[d], y = j + dy[d];
                    
                    if (x < 0 || x >= 10) continue;
                    if (y < 0 || y >= 10) continue;
                    
                    if (board[x][y] == '#') {
                        c++;
                        dir = d;
                    }
                }
                
                if (c == 0) ships[1]++;
                else if (c == 1) {
                    int x = i+dx[dir], y = j + dy[dir];
                    visited[x][y] = true;
                    int s = 1;
                    while (1) {
                        s++;
                        c = 0;
                        for (int d = 0; d < 8; d++) {
                            int a = x+dx[d], b = y + dy[d];
                            
                            if (a < 0 || a >= 10) continue;
                            if (b < 0 || b >= 10) continue;
                            
                            if (board[a][b] == '#') {
                                c++;
                            }
                            if (c > 2) {
                                cout << "NO\n";
                                return 0;
                            }
                        }
                        if (c == 1) {
                            ships[s]++;
                            break;
                        }
                        if (s > 4 || board[x+dx[dir]][y+dy[dir]] != '#') {
                            cout << "NO\n";
                            return 0;
                        }
                        x += dx[dir], y+=dy[dir];
                        visited[x][y] = true;
                    }
                }
                else {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    
    if (ships[1] != 4 || ships[2] != 3 || ships[3] != 2 || ships[4] != 1) {
        cout << "NO\n";
    } else cout << "YES\n";

    return 0;
}