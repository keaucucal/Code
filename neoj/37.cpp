#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    queue<int> q;
    while (t--) {
        int a;
        cin >> a;
        if (a == 1) {
            int n;
            cin >> n;
            q.push(n);
        } else {
            if (q.empty()) cout << "empty!\n";
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }
}
