#include <vector>
using namespace std;

void solve(int n) {
	vector<vector<int>> v(n, vector<int>(n));
	v[0][0] = v[1][1] = 1;
	v[0][1] = 2, v[1][0] = 3;
	
	int cur = 2;
	while (cur <= n / 2) {
		for (int i = 0; i < cur; i++) {
			for (int j = 0; j < cur; j++) {
				v[i + cur][j] = v[i][j] + cur * 2;
				v[i][j + cur] = v[i][j] + cur * 2;
				v[i + cur][j + cur] = v[i][j];
				if (v[i][j] == 1) v[i][j + cur]--;
			}
		}
		cur *= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Report(v[i][j]);
		}
	}
}
