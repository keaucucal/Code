#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e6;

int main() {
	vector<ll> phi(N + 1), ans(N + 1);
	
	// set phi
	for (int i = 1; i <= N; i++) phi[i] = i;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) { // i is prime
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}

	// precalculate answer
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			ans[j] += phi[j / i] * i;
		}
	}

	// make it prefix sum for the queries
	for (int i = 1; i <= N; i++) {
		ans[i] += ans[i - 1];
	}

	int n;
	while (cin >> n) {
		if (n == 0) break;

		cout << ans[n] << '\n';
	}
}
