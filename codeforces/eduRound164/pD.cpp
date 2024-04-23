#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int mod = 998244353;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
