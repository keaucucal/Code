#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 3) {
            cout << "aaa\n";
        } else if (n <= 28) {
            cout << "aa" << char('a' + n - 3) << '\n';
        } else {
            n -= 26;
            if (n > 26) {
                cout << char('a' + n - 27) << 'z';
            } else {
                cout << 'a' << char('a' + n - 2);
            }
            cout << "z\n";
        }
    }
}
