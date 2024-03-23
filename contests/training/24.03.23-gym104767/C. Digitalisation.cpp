#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int students, schools, capacity; 
    cin >> students >> schools >> capacity;

    vector<int> school_list(schools+1, 0); 

    int first = 0, second = 0;

    int x, y;

    for (int i = 0; i < students; i++) {
        cin >> x >> y;

        if (school_list[x] < capacity) {
            school_list[x]++;
            first++;
        }
        else {
            if (school_list[y] < capacity) {
                school_list[y]++;
                second++;
            }
        }
    }

    cout << first << ' ' << second;

    return 0;
}