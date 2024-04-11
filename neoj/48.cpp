#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pre, in;

void build(int cur, int ind, int h) {
	if (h == 0) return;
	int node = pre[cur];
	
	int i = 0;
	while (i < h && in[ind + i] != node) i++;

	// left
	build(cur + 1, ind, i);
	
	// right
	build(cur + i + 1,ind + i + 1, h - i - 1);

	cout << node << '\n';
}

int main() {
	int n;
	cin >> n;
	pre.resize(n);
	for (auto &i : pre) cin >> i;
	in = pre;
	sort(in.begin(), in.end());

	build(0, 0, n);
}
