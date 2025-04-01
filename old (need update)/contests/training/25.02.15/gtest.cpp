#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX;

template<typename T>
pair<int, vector<T>> gauss(vector<vector<T>> a, vector<T> b) {
	const double eps = 1e-6;
	int n = a.size(), m = a[0].size();
	for (int i = 0; i < n; i++) a[i].push_back(b[i]);

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m and row < n; col++) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
		if (abs(a[sel][col]) < eps) continue;
		for (int i = col; i <= m; i++)
			swap(a[sel][i], a[row][i]);
		where[col] = row;

		for (int i = 0; i < n; i++) if (i != row) {
			T c = a[i][col] / a[row][col];
			for (int j = col; j <= m; j++)
				a[i][j] -= a[row][j] * c;
		}
		row++;
	}

	vector<T> ans(m, 0);
	for (int i = 0; i < m; i++) if (where[i] != -1)
		ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i = 0; i < n; i++) {
		T sum = 0;
		for (int j = 0; j < m; j++)
			sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > eps)
			return pair(0, vector<T>());
	}

	for (int i = 0; i < m; i++) if (where[i] == -1)
		return pair(INF, ans);
	return pair(1, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int n; double v, u;
    cin >> n >> v >> u;

    set<double> ss;
    double x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ss.insert(x);
    }
    
    n = ss.size();

    vector<double> b(n, 0);
    int i = 0; for (auto e : ss) b[i++] = e;


    vector<vector<double>> a(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = v;
        }
        a[i][i] = (u + v);
    }

    double answ = 0;
    for (auto e : gauss(a, b).second) {
        answ += u * e;
    }

    cout << answ << endl;

    return 0;
}