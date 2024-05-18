#include <iostream>
#include <vector>
#include <algorithm>
#include <funtional>
using namespace std;

const int INF = 1e9;

int bs(int l, int r, function<bool(int)> check) {
	while (l < r) {
		int mid = l + (r - l) / 2; // accepted, go lower
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> horses(n), growth(n);
	for (int i = 0; i < n; i++) {
		cin >> horses[i] >> growth[i];
	}

	vector<int> opponent(n);
	for (int i = 0; i < n; i++) {
		cin >> opponent[i];
	}

	int ans = INF;


int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
