#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct person {
    vector<int> event;
    int score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int events, people; cin >> events >> people;

    int a, s;
    int b;

    vector<person> pp(people+1, {vector<int>(), INT_MAX});
    vector<int> ee(events+1, 0);

    for (int i = 1; i <= events; i++) {
        cin >> a >> s;

        for (int j = 0; j < a; j++) {
            cin >> b;
            
            if (pp[b].score > s) {
                for (auto e: pp[b].event) {
                    ee[e]--;
                }
                ee[i]++;
                pp[b].score = s;
                pp[b].event = {i};
            }
            else if (pp[b].score == s) {
                ee[i]++;
                pp[b].event.push_back(i);
            }
        }
    }

    for (int i = 1; i <= events; i++) {
        if (ee[i] == 0) {
            cout << "Poor memory\n";
            return 0;
        }
    }

    cout << "Good memory\n";

    for (int i = 1; i <= people; i++) {
        cout << min(1000000000, pp[i].score) << ' ';
    } cout << '\n';

    return 0;    
}