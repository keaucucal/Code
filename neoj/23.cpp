#include <stack>

void solve(int n, int order[]) {
    std::stack<int> left, right; // left -> station 2 / right -> station 1
    int cur = 0;

    for (int i = 1; i <= n; i++) {
        right.push(i);
        push_train();
        while (!right.empty() && right.top() == order[cur]) {
            cur++;
            right.pop();
            move_station_1_to_2();
            pop_train();
        }
    }

    while (!left.empty() || !right.empty()) {
        while (!right.empty()) {
            left.push(right.top());
            right.pop();
            move_station_1_to_2();

            while (!left.empty() && left.top() == order[cur]) {
                cur++;
                left.pop();
                pop_train();
            }

            while (!right.empty() && right.top() == order[cur]) {
                cur++;
                right.pop();
                move_station_1_to_2();
                pop_train();
            }
        }

        while (!left.empty()) {
            right.push(left.top());
            left.pop();
            move_station_2_to_1();

            while (!right.empty() && right.top() == order[cur]) {
                cur++;
                right.pop();
                move_station_1_to_2();
                pop_train();
            }

            while (!left.empty() && left.top() == order[cur]) {
                cur++;
                left.pop();
                pop_train();

            }
        }
    }
}
