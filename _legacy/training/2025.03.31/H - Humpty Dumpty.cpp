/*
Lucas Guimarães Fernandes </lgf_cin>
MaratonaCIn @ CIn - UFPE

[Humpty Dumpty](https://codeforces.com/gym/105741/problem/H)
Rating: NOT DEFINED
Tags: ;

Date: 2025-04-01
Status: Wrong Answer
*/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

map<pii, int> dpmin;
int solve(int x, int y, map<int,map<int, bool>>& board, map<pii, bool>& visited) {
    if (dpmin.count({x,y}) != 0) return dpmin[{x,y}];
    if (y == 1) return dpmin[{x,y}] = 0;
    if (visited[{x,y}]) return INT_MIN;
    visited[{x,y}] = true;


    int answ = INT_MAX;
    if (board[x-1].count(y) == 0) {
        auto l = board[x-1].lower_bound(y-1);
        if (l == board[x-1].begin()) {
            if (l != board[x-1].end()) answ = min(answ, max(solvemin(x-1, 1, board, visited), y-1));
            else answ = min(answ, max(solvemin(x-1, l->first, board, visited), y-1));
        }
        else {
            if (l == board[x-1].end() || l->first != y-1) --l;
            answ = min(answ, max(solvemin(x-1, l->first+1, board, visited), y - l->first - 1));
        }
    }

    if (board[x+1].count(y) == 0) {
        auto r = board[x+1].lower_bound(y-1);
        if (r == board[x+1].begin()) {
            if (r != board[x+1].end()) answ = min(answ, max(solvemin(x+1, 1, board, visited), y-1));
            else answ = min(answ, max(solvemin(x+1, r->first, board, visited), y-1));
        }
        else {
            if (r == board[x+1].end() || r->first != y-1) --r;
            answ = min(answ, max(solvemin(x+1, r->first+1, board, visited), y - r->first - 1));
        }
    }
 
    if (answ == INT_MAX) answ = 0;
 
    return dpmin[{x,y}] = answ;
}

map<pii, int> dpmax;
int solvemax(int x, int y, map<int,map<int, bool>>& board, map<pii, bool>& visited) {
    if (dpmax.count({x,y}) != 0) return dpmax[{x,y}];
    if (y == 1) return dpmax[{x,y}] = 0;
    if (visited[{x,y}]) return INT_MIN;
    visited[{x,y}] = true;

    int answ = INT_MIN;
    if (board[x-1].count(y) == 0) {
        auto l = board[x-1].lower_bound(y-1);
        if (l == board[x-1].begin()) {
            if (l != board[x-1].end()) answ = max(answ, max(solvemax(x-1, 1, board, visited), y-1));
            else answ = max(answ, max(solvemax(x-1, l->first, board, visited), y-1));
        }
        else {
            if (l == board[x-1].end() || l->first != y-1) --l;
            answ = max(answ, max(solvemax(x-1, l->first+1, board, visited), y - l->first - 1));
        }
    }

    if (board[x+1].count(y) == 0) {
        auto r = board[x+1].lower_bound(y-1);
        if (r == board[x+1].begin()) {
            if (r != board[x+1].end()) answ = max(answ, max(solvemax(x+1, 1, board, visited), y-1));
            else answ = max(answ, max(solvemax(x+1, r->first, board, visited), y-1));
        }
        else {
            if (r == board[x+1].end() || r->first != y-1) --r;
            answ = max(answ, max(solvemax(x+1, r->first+1, board, visited), y - r->first - 1));
        }
    }
 
    if (answ == INT_MIN) answ = 0;
 
    return dpmax[{x,y}] = answ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    map<int, map<int, bool>> board;

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

        map<pii, bool> visitedmin, visitedmax;
        
        cout << max(y-y0, solvemax(x, y0, board, visitedmax)) << ' ' << max(y-y0, solvemin(x, y0, board, visitedmin))<< '\n';
    }
    
    return 0;
}