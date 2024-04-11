#include <iostream>
#include <vector>
#include <map>
using namespace std;

// R = 1, Y = 2, B = 4 / O = 3, P = 5, G = 6 / D = 7
map<char, int> m = {{'R', 1}, {'Y', 2}, {'B', 4}, {'O', 3}, {'P', 5}, {'G', 6}, {'D', 7}};

void solve() {
	int n;
	cin >> n;
	
	vector<char> v(3);
	vector<int> x(3), y(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i] >> x[i] >> y[i];
	}

	char c;
	cin >> c;
	int check = m[c];

	int ans = 0;
	for (int t = 0; t <= n; t++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int color = 0;
				for (int k = 0; k < 3; k++) {
					int lx = x[k] - t, rx = x[k] + t;
					int ly = y[k] - t, ry = y[k] + t;
					if (lx <= i && i <= rx && ly <= j && j <= ry) {
						color += m[v[k]];
					}
				}

				if (color == check) cnt++;
			}
		}

		if (cnt < ans) break;
		else ans = cnt;
	}

	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
