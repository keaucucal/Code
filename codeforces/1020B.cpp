#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> adj[i];
	}

	for (int i = 1; i <= n; i++) {
		int a = adj[i];
		int b = adj[adj[i]];
		while (a != b) {
			a = adj[a];
			b = adj[adj[b]];
		}

		a = i;
		while (a != b) {
			a = adj[a];
			b = adj[b];
		}

		cout << a << ' ';
	}
}


// O(n^2)
/*
int main() {
	int n;
	cin >> n;
	vector<int> adj(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> adj[i];
	}
	
	for (int i = 1; i <= n; i++) {
		set<int> s;
		s.insert(i);
		int a = adj[i];
		while (!s.count(a)) {
			s.insert(a);
			a = adj[a];
		}

		cout << a << ' ';
	}

	cout << '\n';
}
*/
