#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[a] = i;
	}

	int pre = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += abs(v[i] - pre);
		pre = v[i];
	}

	cout << ans << '\n';
}
