#include <iostream>
using namespace std;

int main() {
	vector<bool> v;
	v.assign(3, false);
	for (int i = 0; i < 3; i++) cout << v[i] << ' ';

	v[2] = true;
	v[1] = true;
	v.assign(3, false);
	cout << '\n';
	for (int i = 0; i < 3; i++) cout << v[i] << ' ';
}
