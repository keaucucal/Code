#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

struct BST {
	Node *root = nullptr;

	// insert
	Node *insert(Node *node, int val) {
		if (!node) return new Node(val);
		
		if (val > node->data) node->right = insert(node->right, val);
		else if (val < node->data) node->left = insert(node->left, val);

		return node;
	}

	void insert(int val) {
		root = insert(root, val);
	}

	// delete
	Node *minval(Node *node) {
		if (node == nullptr) return nullptr;
		Node *cur = node;
		while (cur->left) cur = cur->left;
		return cur;
	}

	Node *del(Node *node, int val) {
		if (!node) return nullptr;

		if (val > node->data) node->right = del(node->right, val);
		else if (val < node->data) node->left = del(node->left, val);
		else { // delete current one
			if (!node->left) { // if no node on left
				Node *temp = node->right;
				delete node;
				return temp;
			} else if (!node->right) { // if no node on right
				Node *temp = node->left;
				delete node;
				return temp;
			}

			// delete current one
			Node *temp = minval(node->right);
			node->data = temp->data;
			node->right = del(node->right, temp->data);
		}

		return node;
	}

	void del(int val) {
		root = del(root, val);
	}

	// search
	bool search(Node *node, int val) {
		if (!node) return false;
		if (val == node->data) return true;
		else if (val < node->data) return search(node->left, val);
		else return search(node->right, val);
	}
	
	bool search(int val) {
		return search(root, val);
	}
};

int main() {
	BST bst;
	bst.insert(3);
	bst.insert(2);
	bst.insert(6);
	bst.del(6);
	bst.insert(5);

	cout << bst.search(3) << ' ' << bst.search(6) << ' ' << bst.search(4) << '\n';
}
