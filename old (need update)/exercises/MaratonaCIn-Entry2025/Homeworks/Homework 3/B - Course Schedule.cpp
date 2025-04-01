#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int courses, requirements;
    int prev, act;
 
    cin >> courses; cin >> requirements;
 
    vector<vector<int>> adj(courses+1);
    vector<bool> visited(courses+1, false);
    queue<int> answer;
    vector<int> inDregree(courses+1, 0);
 
    for (int i = 0; i < requirements; i++) {
        cin >> prev; cin >> act;
        adj[prev].push_back(act);
        inDregree[act]++;
    }
 
    queue<int> operation_order;
 
    for (int i = 1; i < courses+1; i++) {
        if (inDregree[i] == 0) {
            operation_order.push(i);
        }
    }
 
    while(!operation_order.empty()) {
        int i = operation_order.front();
        operation_order.pop();
        answer.push(i);
 
        for (auto e:adj[i]) {
            if (--inDregree[e] == 0) {
                operation_order.push(e);
            }
        }
    }
    
    if (answer.size() == courses) {
        while (!answer.empty()) {
        cout << answer.front() << " ";
        answer.pop();
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}