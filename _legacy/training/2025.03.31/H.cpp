/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE
 
[Humpty Dumpty](https://codeforces.com/gym/105741/problem/H)
Rating: NOT DEFINED
Tags: ;
 
Date: 2025-04-02
Status: ---
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

vector<map<int, bool>> board(1e5+2);

vector<map<int, int>> maxfall_rght(1e5+2);
vector<map<int, int>> maxfall_left(1e5+2);

vector<map<int, int>> dpmin(1e5+2);
int solvemin(int x, int y) {
    if (dpmin[x].count(y) != 0) return dpmin[x][y];
    if (y == 1) return dpmin[x][y] = 0;

    int answ = INT_MAX;
    
    int x0 = x;
    while (board[x0-1].count(y-1) != 0) {
        if (board[x0-1].count(y) != 0) break;
        x0--;
    }
    if (board[x0-1].count(y) == 0) {
        auto l = board[x0-1].lower_bound(y-1);
        if (l == board[x0-1].begin()) answ = min(answ, max(solvemin(x0-1, 1), y-1));
        else {
            --l;
            answ = min(answ, max(solvemin(x0-1, l->first+1), y - l->first - 1));
        }
    }
    
    x0 = x;
    while (board[x0+1].count(y-1) != 0) {
        if (board[x0+1].count(y) != 0) break;
        x0++;
    }
    if (board[x0+1].count(y) == 0) {
        auto r = board[x0+1].lower_bound(y-1);
        if (r == board[x0+1].begin()) answ = min(answ, max(solvemin(x0+1, 1), y-1));
        else {
            --r;
            answ = min(answ, max(solvemin(x0+1, r->first+1), y - r->first - 1));
        }
    }
 
    if (answ == INT_MAX) answ = 0;
 
    return dpmin[x][y] = answ;
}

vector<map<int,int>> dpmax(1e5+2);
int solvemax(int x, int y) {
    if (dpmax[x].count(y) != 0) return dpmax[x][y];
    if (y == 1) return dpmax[x][y] = 0;

    int answ = INT_MIN;
    int x0 = x;
    while (board[x0-1].count(y-1) != 0) {
        if (board[x0-1].count(y) != 0) break;
        x0--;
    }
    if (board[x0-1].count(y-1) == 0 && board[x0-1].count(y) == 0) {
        auto l = board[x0-1].lower_bound(y-1);
        if (l == board[x0-1].begin()) answ = max(answ, max(solvemax(x0-1, 1), y-1));
        else {
            --l;
            answ = max(answ, max(solvemax(x0-1, l->first+1), y - l->first - 1));
        }
    }

    x0 = x;
    while (board[x0+1].count(y-1) != 0) {
        if (board[x0+1].count(y) != 0) break;
        x0++;
    }
    if (board[x0+1].count(y-1) == 0 && board[x0+1].count(y) == 0) {
        auto r = board[x0+1].lower_bound(y-1);
        if (r == board[x0+1].begin()) answ = max(answ, max(solvemax(x0+1, 1), y-1));
        else {
            --r;
            answ = max(answ, max(solvemax(x0+1, r->first+1), y - r->first - 1));
        }
    }
 
    if (answ == INT_MIN) answ = 0;
 
    return dpmax[x][y] = answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        board[x][y] = true;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;

        int y0;

        auto yb = board[x].lower_bound(y-1);
        if (yb->first == y-1) y0 = y;
        else if (yb == board[x].begin()) y0 =  1;
        else {
            --yb;
            y0 = yb->first + 1;
        }
        
        cout << max(y-y0, solvemax(x, y0)) << ' ' << max(y-y0, solvemin(x, y0))<< '\n';
    }
    
    return 0;
}