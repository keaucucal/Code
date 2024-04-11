#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

char pattern(int i, int j) {
	return ((i + j) % 2 == 0 ? '#' : '.');
}

void solve() {
	int n;
	cin >> n;

	vector<vector<char>> v(n * 2 + 1, vector<char>(n * 2 + 1));
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v[i * 2 - 1][j * 2 - 1] = pattern(i, j); 
			v[i * 2][j * 2 - 1] = pattern(i, j);
			v[i * 2 - 1][j * 2] = pattern(i, j);
			v[i * 2][j * 2] = pattern(i, j);
		}
	}

	for (int i = 1; i <= n * 2; i++) {
		for (int j = 1; j <= n * 2; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
