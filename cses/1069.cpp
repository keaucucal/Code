#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    char c = ' ';
    int sum = 1, ans = 0;
    for (char x : s) {
        if (x == c) sum++;
        else sum = 1;
        c = x;
        
        ans = ans > sum ? ans : sum;
    }

    cout << ans << '\n';
    return 0;
}
