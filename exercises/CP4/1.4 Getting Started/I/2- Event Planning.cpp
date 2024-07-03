#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int people, budget, hotel_number, week_number;
    while (cin >> people >> budget >> hotel_number >> week_number) {
        int price, beds;

        vector<int> budgets;

        for (int i = 0; i < hotel_number; i++) {
            cin >> price;

            for (int j = 0; j < week_number; j++) {
                cin >> beds;
                if (beds >= people) {
                    budgets.push_back(people * price);
                }
            }
        }

        sort(budgets.begin(), budgets.end());

        if (budgets.empty() || budgets[0] > budget) {
            cout << "stay home\n";
        } else {
            cout << budgets[0] << '\n';
        }
    }

    return 0;
}