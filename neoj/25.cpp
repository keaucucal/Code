// 不能用queue會TLE啦
// 但要用linked_list為什麼要那麼詭譎
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
    int data;
    node *next = nullptr;
};

struct linked_list {
    size_t size = 0;
    node *root = nullptr;
    node *end = nullptr;

    bool empty() {
        return !size;
    }

    void add(int id) {
        node *tmp = new node;
        tmp->data = id;
        if (empty()) {
            root = tmp;
            end = tmp;
            size++;
            return;
        }
        size++;
        end->next = tmp;
        end = tmp;
    }

    void leave() {
        node *newRoot = root->next;
        delete root;
        root = newRoot;
        size--;
        if (empty()) end = nullptr;
    }

    void join(linked_list &other) {
        if (other.empty()) return;
        if (empty()) {
            root = other.root;
        } else {
            end->next = other.root;
        }

        end = other.end;
        size += other.size;

        other.size = 0;
        other.root = nullptr;
        other.end = nullptr;
    }

    void print_list() {
        if (empty()) {
            cout << "empty";
        } else {
            node *now = root;
            cout << now->data;
            while (now->next != nullptr) {
                now = now->next;
                cout << ' ' << now->data;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<linked_list> store(n + 1);

    while (m--) {
        string s;
        cin >> s;

        if (s == "ADD") {
            int i, id;
            cin >> i >> id;
            store[i].add(id);
        } else if (s == "LEAVE") {
            int i;
            cin >> i;
            if (store[i].empty()) {
                cout << "queue " << i << " is empty!\n";
            } else {
                store[i].leave();
            }
        } else {
            int i, j;
            cin >> i >> j;
            store[j].join(store[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "queue " << i << ": ";
        store[i].print_list();
        cout << '\n';
    }
}
