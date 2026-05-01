/**
 * Author:      Lua
 * Problem:     C - Coffee
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101991/problem/C
 * Status:      AC
 * Created:     04-04-2026 14:08:17
 **/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int c, p; cin >> c >> p;
    map<string, array<int, 3>> prices;

    for (int i = 0; i < c; i++) {
        string name; cin >> name;
        for (auto &x : prices[name]) cin >> x;
    }

    map<string, int> sizeToInt = {
        {"small", 0},
        {"medium", 1},
        {"large", 2}
    };

    int fee = 100/p;

    for (int i = 0; i < p; i++) {
        string name, size, coffee; cin >> name >> size >> coffee;
        int price = prices[coffee][sizeToInt[size]] + fee;

        if (price % 5 == 1) price--;
        if (price % 5 == 4) price++;

        cout  << name << ' ' << price << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("coffee.in", "r", stdin);

    int tc; cin >> tc; while (tc--) solve();

    return 0;
}