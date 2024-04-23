#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int a, int b) {
	auto ask = [&](string s) -> int {
		cout << s << ' ' << a << ' ' << b << endl;
		int ret;
		cin >> ret;
		return ret;
	};

	int AND = ask("and");
	int OR = ask("or");
	int XOR = AND ^ OR;

	return AND * 2 + XOR;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);

	int ab = sum(1, 2), ac = sum(1, 3), bc = sum(2, 3);
	v[1] = (ab + ac - bc) / 2;
	v[2] = ab - v[1], v[3] = ac - v[1];

	for (int i = 4; i <= n; i++) {
		v[i] = sum(i - 1, i) - v[i - 1];
	}

	sort(v.begin(), v.end());
	cout << "finish " << v[k] << endl;
}
