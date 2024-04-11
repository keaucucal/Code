#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        priority_queue<int> b;
        for (auto &i : a) cin >> i;
        while (m--) {
            int tmp;
            cin >> tmp;
            b.push(tmp);
        }

        for (const auto &i : a) {
            while (!b.empty() && b.top() >= i) {
                cout << b.top() << ' ';
                b.pop();
            }
            
            cout << i << ' ';
        }

        while (!b.empty()) {
            cout << b.top() << ' ';
            b.pop();
        }

        cout << '\n';
    }

    return 0;
}
