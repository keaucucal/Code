#include <iostream>
#include <vector>
using namespace std;

struct segmentTree {
	int n;
	vector<int> v;

	segmentTree(int N, vector<int> data) : n(N), v(N << 1) {
		for (int i = n; i < (n << 1); i++) {
			v[i] = data[i - n];
		} 

		for (int i = n - 1; i > 0; i--) {
			v[i] = max(v[i * 2], v[i * 2 + 1]);
		}
	}

	int query(int l, int r) {
		l += n, r += n;
		int ret = 0;
		while (l <= r) {
			if (l % 2 == 1) ret = max(ret, v[l++]);
			if (r % 2 == 0) ret = max(ret, v[r--]);
			l >>= 1, r >>= 1;
		}
		
		return ret;
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto &x : v) cin >> x;

	segmentTree st(n, v);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << st.query(--l, --r) << '\n';
	}
}
