#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> dirx = {1,2,-1,-2, 1,2,-1,-2};
vector<int> diry = {2,1,2,1, -2,-1,-2,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<vector<int>> board(n, vector<int>(n,0));
    vector<pair<int,int>> knights;

    for(int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        r--;
        c--;
        board[r][c] = 1;
        knights.push_back({r,c});
    }

    vector<vector<int>> attacks(n, vector<int>(n,0));
    //map<pair<int,int>, vector<pair<int,int>>> mp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                vector<vector<int>> vis(n, vector<int>(n,0));
                for(int d = 0; d < 8; d++) {
                    int a = i + dirx[d];
                    int b = j + diry[d];

                    if (a >= 0 && b >= 0 && a < n && b < n && board[a][b] == 1 && vis[a][b] == 0) {
                        attacks[a][b]++;
                        vis[a][b] = 1;
                    }
                }
            }
        }   
    }

    int c = 0;

    while (true) {
        int mx = 1e9;
        for (auto [r,c] : knights) {
            if (attacks[r][c] > 0) {
                mx = min(mx, attacks[r][c]);
            }
        }
        if (mx == 1e9) break;

        

        for (auto [i,j] : knights) {
            if (attacks[i][j] == mx) {
                for(int d = 0; d < 8; d++) {
                    int a = i + dirx[d];
                    int b = j + diry[d];

                    if (a >= 0 && b >= 0 && a < n && b < n && board[a][b] == 1) {
                        c++;
                        attacks[a][b] = 0;
                        board[a][b] = 0;
                        for(int e = 0; e < 8; e++) {
                            int aa = a + dirx[e];
                            int bb = b + diry[e];

                            if (aa >= 0 && bb >= 0 && aa < n && bb < n && board[aa][bb] == 1) {
                                attacks[aa][bb]--;
                            }
                            
                        }
                        
                    }
                    
                }
                break;
            }
        }
    }

    cout << c << endl;

}