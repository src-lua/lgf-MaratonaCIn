#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int costumers, breads, positions, queries; 
    cin >> costumers >> breads >> positions >> queries;

    vector<int> locations(costumers);
    vector<vector<int>> equador(positions, vector<int>(breads, 0));

    int x;
    for (int i = 0; i < costumers; i++) {
        cin >> locations[i];
    }

    for (int i = 0; i < costumers; i++) {
        cin >> x;
        equador[locations[i]][x] = 1;
    }


    for (int i = 0; i < positions; i++) {
        for (int j = breads-2; j >= 0; j--) {
            if (equador[i][j] != 0) equador[i][j] += equador[i][j+1];
        }
        if (equador[i][0] != 0) {
            
            for (int j = breads-1; j >= 0; j--) {
            
                if (j == 0) {
                    for (int b = 0; b < breads; b++) {
                        equador[i][b] = INT_MAX;
                    }
                    break;
                }
                    
                if(equador[i][j] != 0) equador[i][j] += equador[i][0];
                else break;
                
            }
            
        }   
    }

    
    int actual_pos;
    int actual_bread;
    int actual_goal = 0;
    int goal;
    int answ = 0;

    int k;

    for (int i = 0; i < queries; i++) {
        cin >> actual_pos >> actual_bread >> goal;

        while (1) {
            k = equador[actual_pos][actual_bread];

            actual_bread = (actual_bread + k) % breads;
            actual_goal += k;
            
            if (actual_goal >= goal) {
                cout << answ << endl;

                answ = 0; actual_goal = 0;
                break;
            }

            actual_pos = (actual_pos + 1) % positions;
            answ += 1;
        }
    }

    return 0;
}