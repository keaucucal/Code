#include <iostream>
#include <vector>
using namespace std;

inline vector<int> move(const vector<int> &target) {
	cout << "next ";
	for (int i = 0; i < target.size() - 1; i++) {
		cout << target[i] << ' ';
	}
	cout << target.back() << endl;

	int n;
	cin >> n;
	vector<int> groups(10);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			groups[c - '0'] = i;
		}
	}

	return groups;
}

int main() {
	move({0, 1});
	vector<int> groups = move({1});
	
	// find a cycle
	while (groups[0] != groups[1]) {
		move({0, 1});
		groups = move({1});
	}

	// find the starting point of a cycle
	// the number >= 2 is at home
	while (groups[2] != groups[1]) {
		groups = move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}

	cout << "done" << endl;
}
