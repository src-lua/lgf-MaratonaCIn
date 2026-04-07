/**
 * Author:      Lua
 * Problem:     J - Jury Jeopardy
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/J
 * Status:      AC
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

void solve() {
    vector<vector<char>> maze(201, vector<char>(101, '#'));

    string s; cin >> s;

    int min_row = 101, max_row = 101;
    int min_col = 0  , max_col = 0  ;
    
    int curr_row = 101, curr_col = 0;

                //  R   D   L   U 
    int d_row[] = {+0, +1, +0, -1}; 
    int d_col[] = {+1, +0, -1, +0};

    int curr_dir = 0;

    for (auto nxt : s) {
        if (nxt == 'F') {
            // nop   
        }

        else if (nxt == 'B') {
            curr_dir = (curr_dir + 2) % 4;
        }

        else if (nxt == 'R') {
            curr_dir = (curr_dir + 1) % 4;
        }

        else if (nxt == 'L') {
            curr_dir = (curr_dir - 1 + 4) % 4;
        }

        curr_row += d_row[curr_dir];
        curr_col += d_col[curr_dir];

        maze[curr_row][curr_col] = '.';

        min_row = min(min_row, curr_row);
        max_row = max(max_row, curr_row);

        min_col = min(min_col, curr_col);
        max_col = max(max_col, curr_col);
    }

    min_row--; max_row++; max_col++;
    
    cout << max_row - min_row + 1 << ' ' 
         <<  max_col - min_col + 1 << '\n';

    for (int row = min_row; row <= max_row; row++) {
        for (int col = min_col; col <= max_col; col++) {
            cout << maze[row][col]; 
        } cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc; cout << tc << '\n'; while(tc--) solve();

    return 0;
}
