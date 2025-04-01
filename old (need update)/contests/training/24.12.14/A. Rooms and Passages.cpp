#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int fix(vector<int>& arr, int i) {
    if (i >= arr.size()) return 0;
    if (arr[i] != -1) return arr[i];
    return arr[i] = fix(arr, i+1)+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> rooms(n);

    for (int i = 0; i < n; i++) cin >> rooms[i];

    vector<int> arr(n, -1);

    deque<int> m;
    deque<int> m2;

    for (int i = 0; i < n; i++) {
        auto e = rooms[i];
        if (e < 0) {
            m.push_back(i);
            m2.push_back(abs(e));
        }
        else {
            bool flag = false;
            int s = m2.size() -1;

            for (; s >= 0; s--) {
                if (m2[s] == e) {
                    s += 1;
                    flag = true;
                    break;
                }
            }
            

            


            if (flag)
            for (int _ = 0; _ < s; _++) {
                arr[m.front()] = i - m.front();
                m.pop_front();
                m2.pop_front();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fix(arr, i);
    }

    for (auto e : arr) cout << e << ' ' ;
    cout << endl;
    

    return 0;
}