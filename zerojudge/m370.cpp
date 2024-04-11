#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    int min = 1000, max = 0;
    int left = 0, right = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a > x) right++;
        else left++;
        
        if (a < min) min = a;
        if (a > max) max = a;
    }

    if (right > left) cout << right << ' ' << max;
    else cout << left << ' ' << min;
}
