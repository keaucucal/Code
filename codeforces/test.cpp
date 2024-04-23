#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = {12, 1623, 1236, 2345 ,1};

	sort(v.begin(), v.end());
	cout << v[0] << ' ';
}
