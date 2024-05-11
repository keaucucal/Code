#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 1; i < n; i++) {
		cin >> x[i];
	}

	vector<int> a(n);
	a[n - 1] = INF;
	for (int i = n - 2; i >= 0; i--) {
		a[i] = a[i + 1] - x[i + 1];
	}

	for (auto i : a) cout << i << ' ';
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

