#include <iostream>
#include <string>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;

	int k = 0;
	for (int i = 0; i < m; i++) {
		if (a[k] == b[i]) {
			k++;
		}
	}
			
	cout << k << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
