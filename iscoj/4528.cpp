#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
#define int long long

signed main() {
	string s;
	cin >> s;
	
	vector<int> v;
	int i;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == '.') break;
		v.push_back(s[i] - '0');
	}

	int times = 1;
	int a = 0;
	for (int j = v.size() - 1; j >= 0; j--) {
		a += v[j] * times;
		times *= 10;
	}

	v.clear();
	for (i = i + 1; i < s.length(); i++) {
		v.push_back(s[i] - '0');
	}

	times = 1;
	int b = 0;
	for (int j = v.size() - 1; j >= 0; j--) {
		b += v[j] * times;
		times *= 10;
	}

	int q = pow(10, v.size()) - 1;
	int p = a * q + b;
	cout << p / gcd(p, q) << '/' << q / gcd(p, q) << '\n';
}
		
