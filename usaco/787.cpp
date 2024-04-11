#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> cows(n);
    for (auto &i : cows) cin >> i;

    vector<pair<int, int>> milk(m);
    for (auto &i : milk) cin >> i.second >> i.first;

    vector<int> rent(r);
    for (auto &i : rent) cin >> i;

    sort(cows.begin(), cows.end(), greater<int>());
    sort(milk.begin(), milk.end(), greater<pair<int, int>>());
    sort(rent.begin(), rent.end(), greater<int>());

    int a = 0, milk_index = 0, rent_index = 0;
    long long ans = 0;
    while (a < n) {
        int cur_milk = cows[a];
        
        // count how much can be made by selling its milk
        int i = milk_index, money = 0, cost;
        while (i < m) {
            cost = min(cur_milk, milk[i].second);
            money += milk[i].first * cost;
            cur_milk -= cost;

            if (cur_milk == 0) break;
            else i++;
        }
         
        // compare it to the money be made by renting a cow
        if (rent_index >= r || money > rent[rent_index]) { // milk
            ans += money;
            milk_index = i;
            if (milk_index < m) milk[i].second -= cost;
            a++;
        } else { // rent
            ans += rent[rent_index];
            rent_index++;
            n--;
        }
    }

    cout << ans << '\n';
}
