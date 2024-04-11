#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vector<int> v(n);
	for (auto &i : v) cin >> i;

	for (int i = n - 2; i >= 0; i--) {
		if (v[i] > v[i + 1]) {
			if (v[i] / 10 > v[i] % 10 || v[i] % 10 > v[i + 1]) {
				cout << "NO\n";
				return;
			} else {
				v[i] = v[i] / 10;
			}
		}
	}

	cout << "YES\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
