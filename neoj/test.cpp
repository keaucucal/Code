#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(20);
	for (int i = 1; i < 20; i++) v[i] = i;
	for (auto i : v++) cout << i << ' ';
}
