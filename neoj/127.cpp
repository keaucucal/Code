#include <vector>
using namespace std;

vector<int> ans;

void DC(int u, int d, int l, int r) {
	int mid = (u + d) / 2;
	int res = 0, ind = 0;
	for (int i = l; i <= r; i++) {
		int t = GetVal(mid, i);
		if (t > res) { // update ansewr
			res = t;
			ind = i;
		}
	}

	ans[mid] = ind;

	if (u < d) {
		DC(u, mid, l, ind);
		DC(mid + 1, d, ind, r);
	}
}

void solve(int n, int m) {
	ans.resize(n + 1);
	DC(1, n, 1, m);
	for (int i = 1; i <= n; i++) Report(ans[i]);
}
