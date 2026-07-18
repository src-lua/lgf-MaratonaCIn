#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int row = s.size();
    int col = t.size();

    // vector<vector<int>> table(++row, vector<int>(++col, 0));

    int table[++row][++col];
    
    for (int i = 0; i < row; i++) { //setting corners to 0;
        table[i][0] = 0;
    }
    for (int j = 0; j < col; j++) { //setting corners to 0;
        table[0][j] = 0;
    }

    for (int i = 1; i < row; i++) { // populating the table;       
        for (int j = 1; j < col; j++) {
            table[i][j] = max(table[i-1][j], table[i][j-1]);
            if (s[i-1] == t[j-1]) table[i][j] = max(table[i][j], table[i-1][j-1] + 1);
        }
    }
    
    

    // for (int i = 0; i < row; i++) { // printing table for debug;
    //     cout << '\n';
    //     for (int j = 0; j < col; j++) {
    //         cout << table[i][j] << " ";
    //     }
    // }
    // cout << '\n';

    //

    deque<char> chosen_itens; // retrieving the chosen itens in the optimal solution
    int r = row-1;
    int c = col-1;
    while (r && c) {
        if (table[r][c] != table[r-1][c]) {
            chosen_itens.push_front(s[r-1]);
            c--; r--;
        }
        else if (table[r][c-1] >= table[r-1][c]) {
            c--;
        }
        else r--;
    }

    for (auto e: chosen_itens) cout << e; //print the chosen itens;

    return 0;
}