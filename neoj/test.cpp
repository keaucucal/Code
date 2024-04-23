#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.resize(1, 0);
	v.clear();
	cout << v.size() << ' ' << ++v[10000000];
}
