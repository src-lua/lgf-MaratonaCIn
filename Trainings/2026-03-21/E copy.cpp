/**
 * Author:      Lua
 * Problem:     E - Excellent Engineers
 * Link:        https://codeforces.com/group/yc7Yxny414/contest/101512/problem/E
 * Status:      ~
 * Created:     21-03-2026 09:04:56
 **/

#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int,int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<iii> arr(n);
    for (auto &[x,  y, z] : arr) cin >> x >> y >> z;

    sort(arr.begin(), arr.end());

    int mx_x, mx_y, mx_z, mn_x, mn_y, mn_z;
    {
        auto [x, y, z] = arr[0];
        mx_x = x, mx_y = y, mx_z = z;
    }

    int i = 0;
    //pego todos os maiores X
    while(i < n && get<0>(arr[i]) == mx_x) {
        mn_y = min(mn_y, get<1>(arr[i]));
        mn_z = min(mn_z, get<2>(arr[i]));

        i++;
    }
    

    // pego todos os caras que tem um Z maior que os primeiros X
    while(i < n && get<2>(arr[i]) > mn_z) {
        mn_x = min(mn_x, get<0>(arr[i]));

        i++;
    }
    // pego todos os caras que tem um Y maior que os primeiros X
    while(i < n && get<1>(arr[i]) > mn_y) {
        mn_x = min(mn_x, get<0>(arr[i]));

        i++;
    }

    // pego todos os caras que tem X maior que os primeiros Y
    // pego todos os caras que tem um Z maior que os primeiros Y

    // pego todos os caras que tem X maior que os primeiros Z


    
    

    return 0;
}
