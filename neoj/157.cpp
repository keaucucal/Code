#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define weight first
#define value second
const int INF = 1e9;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	int v = 0;
	for (auto &x : arr) {
		cin >> x.weight >> x.value;
		v += x.value;
	}

	vector<int> dp(v + 1, INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = v; j >= 0; j--) {
			if (j >= arr[i].value) {
				dp[j] = min(dp[j], dp[j - arr[i].value] + arr[i].weight);
			}
		}
	}

	while (dp[v] > m) {
		v--;
	}

	cout << v << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
