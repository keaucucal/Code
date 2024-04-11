// Sprout OJ 59: heap 練習
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    priority_queue<int, vector<int>, greater<int>> pq;
    while(T--) {
        int a;
        cin >> a;

        if(a == 2) {
            if(pq.empty()) {
                cout << "empty!\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
            continue;
        }

        cin >> a;
        pq.push(a);
    }

    return 0;
}
