#include <vector>
using namespace std;

vector<int> v;
void initialize(int n) {
	v.resize(n, 0);
	v.clear();
}

int hasEdge(int a, int b) {
	return ++v[max(a, b)] == max(a, b);
}
