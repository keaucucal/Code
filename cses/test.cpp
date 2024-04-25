#include <iostream>
using namespace std;

int main() {
	int a = 2000000000;
	int b = 2000000000;
	long long c = (long long) a * b;
	a *= 2000000000;
	b *= 2000000000;
	cout << a << ' ' << b << ' ' << c <<  '\n';
}
