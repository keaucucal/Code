#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int &i : coin) cin >> i;

    vector<int> value(x + 1);
    value[0] = 0;
    for (int i = 1; i <= x; i++) {
        value[i] = INF;
        for (const int c : coin) {
            if (i - c >= 0) {
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }
    
    value[x] = (value[x] == INF ? -1 : value[x]); 
    cout << value[x] << '\n';
    return 0; 
}
