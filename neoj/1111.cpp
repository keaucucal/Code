// Sprout NEOJ No.1111 撲克牌排序問題 https://neoj.sprout.tw/problem/1111/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, string>> v;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if(s == "J") {
            cnt++;
            continue;
        }

        int tmp = 100;
        switch (s[1]) {
            case 'A':
                tmp *= 1;
                break;
            case '1':
                tmp *= 10;
                break;
            case 'J':
                tmp *= 11;
                break;
            case 'Q':
                tmp *= 12;
                break;
            case 'K':
                tmp *= 13;
                break;
            default:
                tmp *= s[1] - '0';
        }
        tmp += s[0] - 'A';

        v.push_back(make_pair(tmp, s));
    }

    sort(v.begin(), v.end());

    cout << v[0].second;
    for(int i = 1; i < N - cnt; i++) {
        cout << ' ' << v[i].second;
    }
    while (cnt--) cout << " J";
    cout << '\n';

    return 0;
}

