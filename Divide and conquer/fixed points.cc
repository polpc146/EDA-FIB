#include <iostream>
#include <vector>
using namespace std;

int fixed_point(vector <int>& vec, int& a, int esq, int dre) {
	if (esq <= dre) {
		int m = (esq+dre) / 2;
		if (vec[m]+a < m+1) return fixed_point(vec, a, m+1, dre);
		else if (vec[m]+a > m+1) return fixed_point(vec, a, esq, m-1);
		else {
			int point = fixed_point(vec, a, esq, m-1);
			if (point == -1) return m+1;
			else return point;
		}
	}
	return -1;
}

int main() {
	int n, m, x, s = 1;
	while (cin >> n) {
		vector <int> vec(n);
		for (int i = 0; i < n; ++i) cin >> vec[i];

		cin >> m;
		cout << "Sequence #" << s << endl;
		for (int i = 0; i < m; ++i) {
			cin >> x;
			int res = fixed_point(vec, x, 0, n-1);
			if (res != -1) cout << "fixed point for " << x << ": " << res << endl;
			else cout << "no fixed point for " << x << endl;
		}
		cout << endl;
		++s;
	}
}
