#include <iostream>
#include <vector>
using namespace std;

struct BIT {
	int n;
	vector<int> tree;

	BIT(vector<int> &data) : n(data.size()){
		tree.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			update(i, data[i - 1]);
		}
	}

	void update(int k, int x) {
		while (k <= n) {
			tree[k] += x;
			k += k & -k;
		}
	}

	int query(int k) {
		int sum = 0;
		while (k >= 1) {
			sum += tree[k];
			k -= k & -k;
		}

		return sum;
	}
};

int main() {
	vector<int> data = {3, 1, 4, 1, 5};
	BIT tree(data);

	for (int i = 1; i <= 5; i++) cout << tree.query(i) << ' ';
}
