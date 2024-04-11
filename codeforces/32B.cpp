#include <iostream>
using namespace std;

int main() {
    char c;
    while (cin >> c) {
        if (c == '.') cout << 0;
        else {
            char temp;
            cin >> temp;
            if (temp == '.') cout << 1;
            else cout << 2;
        }
    }

    cout << '\n';
    return 0;
}
