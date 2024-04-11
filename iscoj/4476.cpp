#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    unordered_map<int, int> ump;

    while (N--) {
        int w;
        cin >> w;
        if (ump.find(w) == ump.end()) cout << "N\n";
        else cout << "Y " << ump[w] << '\n';
        ump[w]++;
    }

    return 0;
}

