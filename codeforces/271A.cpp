#include <iostream>
using namespace std;

int main() {
    bool b[10] = {false};
    
    for (int i = 0; i < 4; i++) {
        char c;
        cin >> c;
        int a = c - '0';

        while (b[a]) a++;
        cout << a;
        b[a] = true;
    }

    return 0;
}
