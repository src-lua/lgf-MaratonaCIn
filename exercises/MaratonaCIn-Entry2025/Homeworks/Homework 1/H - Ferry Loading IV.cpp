#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, ferry_lenght, cars, car_lenght, count, actual_lenght;
    string side;
    queue<int> right;
    queue<int> left;

    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> ferry_lenght;
        cin >> cars;

        for (int i = 0; i < cars; i++) {
            cin >> car_lenght;
            cin >> side;

            if (side == "right") right.push(car_lenght);
            else if (side == "left") left.push(car_lenght);
        }
        count = 0;
        while (left.empty() == false || right.empty() == false) {
            count++;
            actual_lenght = 0;

            if (count%2 == 1) {
                while (left.empty() == false && actual_lenght + left.front() < (ferry_lenght*100)) {
                    actual_lenght += left.front();
                    left.pop();
                }
            }

            if (count%2 == 0) {
                while (right.empty() == false && actual_lenght + right.front() < (ferry_lenght*100)) {
                    actual_lenght += right.front();
                    right.pop();
                }
            }   
        }
        cout << count << '\n';
    }
    return 0;
}