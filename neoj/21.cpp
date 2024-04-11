// NEOJ 21 陸行鳥大賽車
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> prev(N + 1, 0), next(N + 1, 0);

    next[1] = 2, prev[1] = 0;
    for (int i = 2; i < N; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    prev[N] = N - 1; next[N] = 0;
    int it = 1;

    int M;
    cin >> M;
    while (M--) {
        bool T;
        int x;
        cin >> T >> x;

        if (T == 0) { // kill
            if (it == x) {
                it = next[x];
                continue;
            }
            prev[next[x]] = prev[x];
            next[prev[x]] = next[x];
        } else { // swap 
            if (it == x) continue;
            if (prev[x] == it) it = x;
            int tmpNx = next[x];
            int tmpPx = prev[x];
            next[prev[prev[x]]] = x;
            next[x] = prev[x];
            prev[x] = prev[prev[x]];
            next[tmpPx] = tmpNx; 
            prev[tmpNx] = tmpPx;
            prev[tmpPx] = x;
        }
    }

    cout << it;
    while (next[it] != 0) {
        it = next[it];
        cout << ' ' << it;
    }
    cout << '\n';

    return 0;
}
