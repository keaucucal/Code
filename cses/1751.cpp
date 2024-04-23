#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> adj[i];
	}

	vector<bool> visited(n + 1);
	vector<int> dist(n + 1);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			cout << dist[i] << ' ';
		} else {
			queue<int> q;
			int a = i;
			int cnt = 0;
			while (true) {
				q.push(a);
				if (visited[a]) {
					cnt += dist[a];
					break;
				}

				visited[a] = true;
				cnt++, a = adj[a];
			}

			cout << cnt << ' ';

			int cost = 1;
			while (!q.empty()) {
				// loop
				if (q.front() == q.back()) cost = 0;
				dist[q.front()] = cnt;
				cnt -= cost;
				q.pop();
			}
		}
	}
}
