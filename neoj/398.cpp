#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &x : v) {
		char trash;
		cin >> trash >> trash >> x;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans += (v[i] + v[j] == v[k]);
			}
		}
	}

	cout << ans << '\n';
}
