#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;
vector<int> v(N + 5);

int main() {
	for (int i = 2; i <= N; i++) {
		if (v[i]) continue;

		for (int j = i; j <= N; j += i) {
			v[j] = i;
		}
	}

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;

		int ans = 1;
		while (x > 1) {
			int prime = v[x], cnt = 0;
			while (x % prime == 0) {
				cnt++;
				x /= prime;
			}

			ans *= (cnt + 1);
		}

		cout << ans << '\n';
	}
}
