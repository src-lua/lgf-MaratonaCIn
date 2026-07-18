#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int a, b, c; cin >> a >> b >> c;

    if ((a*2)+b+1 != a+b+c) {
        return -1;
    }

    vector<int> capacity(1e5,0);

    capacity[0] = 1;

    int index = 0;

    while (1) {
        if (capacity[index] > 0) {
            capacity[index]--;
            if (a > 0) {
                a--;
                capacity[index+1]+=2;
            }

            else if (b > 0) {
                b--;
                capacity[index+1]+=1;
            }

            else if (c > 0) {
                c--;
            }

            else {
                break;
            }
        }

        else if (capacity[index+1] != 0){
            index++;
        }

        else {
            break;
        }
    }

    return index;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        cout << solve() << endl;
    }

    return 0;
}