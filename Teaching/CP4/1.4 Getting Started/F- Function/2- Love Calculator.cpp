#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int getValue(string s) {
    int sum = 0;
    for (int e : s) {
        if (e >= 'A' && e <= 'Z') {
            sum +=e - 'A'  + 1;
        } else if (e >= 'a' && e <= 'z') {
            sum += e - 'a' + 1;
        }
    }

    while (sum >= 10) {
        int temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(2);

    string s1, s2;

    while(getline(cin, s1)) {
        getline(cin, s2);

        float a = getValue(s1);
        float b = getValue(s2);

        cout << min(a,b)/max(a,b) * 100 << " %\n";

    }

    return 0;
}