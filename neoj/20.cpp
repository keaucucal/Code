// Sprout OJ (NEOJ) No.20: 中國人排隊問題（？
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Line #" << k << '\n';

        int N;
        cin >> N;

        vector<int> mp(1e6 + 7, -1);
        for (int i = 0; i < N; i++) {
            int K;
            cin >> K;
            while (K--) {
                int x;
                cin >> x;
                mp[x] = i;
            }
        }

        int M;
        cin >> M;
        queue<int> q;
        vector<queue<int>> vq(N + 1);
        int dir;
        while (M--) {
            string s;
            cin >> s;
            
            if (s == "DEQUEUE") {
                dir = q.front();

                cout << vq[dir].front() << '\n';
                vq[dir].pop();
                if (vq[dir].empty() || dir == N) q.pop();
                continue;
            }

            int x;
            cin >> x;
            if (mp[x] == -1) {
                vq[N].push(x);
                q.push(N);
                continue;
            }
            dir = mp[x];
            if (vq[dir].empty()) q.push(dir);
            vq[dir].push(x);
        }
    }

    return 0;
}
