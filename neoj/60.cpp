#include <iostream>
#include <functional>
using namespace std;

int A, B, C, D, M, S, T;

// Binary Search on the time
int bs(int l, int r, function<bool(int)> check) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Normal speed : A / Speed up speed : B -> cost C per second / gain D per second if stop
	cin >> A >> B >> C >> D;

	// initial gas : M / S distance / time limit : T
	cin >> M >> S >> T;
	
	// count the maximum dist you can reach with t second
	auto maxDist = [&](const int &t) -> int {
		int rush = M / C;
		if (rush >= t) {
			return t * B;
		}

		int ret = 0; // maximum distance
		int N = t - rush;
		for (int i = 0; i <= N; i++) { // stop for i seconds
			int cur = rush + i;
			int gas = (M % C) + (D * i);
			int pos = B * rush;

			int left = min(gas / C, t - cur);
			pos += left * B;
			cur += left;

			pos += A * (t - cur);
			ret = max(ret, pos);
		}

		return ret;
	};

	// if possible -> fastest time / impossible -> longest distance reachable
	if (maxDist(T) <= S) {
		cout << "No\n" << maxDist(T) << '\n';
	} else {
		cout << "Yes\n" << bs(0, T, [&](const int &time) -> bool {
				return maxDist(time) > S;
			}) << '\n';
	}
}
