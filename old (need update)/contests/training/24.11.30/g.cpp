#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    priority_queue<int> max_heap;

    for (int i = 1; i < n; i++) {
        max_heap.push(arr[i]-arr[i-1]);
    }

    for (int i = 0; i < k; i++) {
        max_heap.push(max_heap.top()/2);
        max_heap.push(max_heap.top()/2);
        max_heap.pop();
    }
    
    int answ = -1;
    while (!max_heap.empty()) {
        answ = max_heap.top();
        max_heap.pop();
    }

    cout << answ << '\n';

    return 0;
}