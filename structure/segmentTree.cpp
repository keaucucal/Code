#include <iostream>
#include <vector>
using namespace std;

struct segmentTree {
    int n;
    vector<int> v;

    segmentTree(int N, vector<int> data) : n(N), v(N << 1) {
        for (int i = n; i < n * 2; i++) {
            v[i] = data[i - n];
        }
        for (int i = n - 1; i > 0; i--) {
            v[i] = v[i * 2] + v[i * 2 + 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        l += n, r += n;
        while (l <= r) {
            if (l % 2 == 1) ans += v[l++];
            if (r % 2 == 0) ans += v[r--];
            l >>= 1, r >>= 1;
        }

        return ans;
    }
};

int n;
struct segment_tree {
	vector<int> tree, tag, data;
	segment_tree(vector<int> &data) : data(data){
		tree.resize(n << 2);
		tag.resize(n << 2);
		build();
		for (auto &i : tree) cout << i << ' ';
		cout << '\n';
	}

	// update the tree
	void pull(int k) {
		tree[k] = tree[k * 2] + tree[k * 2 + 1];
	}

	// build the tree
	void build(int l = 0, int r = n - 1, int k = 1) {
		if (l == r) {
			tree[k] = data[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, k * 2);
		build(mid + 1, r, k * 2 + 1);
		pull(k);
	}

	// add the tag
	void addtag(int val, int k) {
		tree[k] += val;
		tag[k] += val;
	}

	// push the tag down
	void push(int k) {
		addtag(tag[k], k * 2);
		addtag(tag[k], k * 2 + 1);
		tag[k] = 0;
	}
		
	// range [x, y] add data
	void modify(int x, int y, int data, int k = 1, int l = 0, int r = n - 1) {
		if (r < x || l > y) return;
		if (l >= x && r <= y) {
			addtag(data * (r - l + 1), k);
			return;
		}
		int mid = (l + r) / 2;
		modify(x, y, data, k * 2, l, mid);
		modify(x, y, data, k * 2 + 1, mid + 1, r);
		pull(k);
	}
		

	// range [x, y] sum
	int query(int x, int y, int k = 1, int l = 0, int r = n - 1) {
		if (r < x || l > y) return 0;
		if (l >= x && r <= y) return tree[k];
		push(k);
		int mid = (l + r) / 2;
		return query(x, y, k * 2, l, mid) + query(x, y, k * 2 + 1, mid + 1, r);
	}
};

int main() {
    vector<int> data = {3, 1, 4, 1, 5};
	n = data.size();
	
	segment_tree tree(data);

	/*
	cout << tree.query(0, 3) << '\n';
	tree.modify(0, 3, 4);
	cout << tree.query(0, 3);
	*/
}
