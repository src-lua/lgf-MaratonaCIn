#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
const int dx[] = {1, -1};

// Time Complexity: O(V + E)
void bfs(vector<int>& arr, vector<int>& dist, vector<int> init) {
    queue<int> operation_order;

    for (auto start : init) {
        dist[start] = 0;
        operation_order.push(start);
    }

    while (!operation_order.empty()) {
        auto top = operation_order.front();
        operation_order.pop();

        for (auto d : dx) {
            auto e = top + d;

            if (e < 0 || e >= arr.size()) continue;

            if (dist[e] == -1) {
                dist[e] = dist[top] + 1;
                operation_order.push(e);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> init;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) init.push_back(i);
    }

    vector<int> dist(n, -1);

    bfs(arr, dist, init);

    for (auto e : dist) cout << e << ' ';
    cout << endl;

    return 0;
}