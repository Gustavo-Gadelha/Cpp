#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  int key;
  Node* left = nullptr;
  Node* right = nullptr;
  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

struct BSTree {
  Node* root = nullptr;

  void insert(int data, int key) { insert_iterative(data, key); }

  void insert_iterative(int data, int key) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->key = key;

    if (root == nullptr) {
      root = newNode;
      return;
    }

    Node* parent = nullptr;
    Node* cur = root;
    while (cur != nullptr) {
      parent = cur;
      if (key == cur->key) {
        cout << "Duplicate keys are not allowed in BSTree." << endl;
        delete newNode;
        exit(1);
      } else if (key < cur->key) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }

    if (key < parent->key)
      parent->left = newNode;
    else
      parent->right = newNode;
  }

  Node* search(int key) { return search(root, key); }
  Node* search(Node* node, int key) {
    if (!node)
      return nullptr;
    if (key == node->key)
      return node;
    if (key < node->key)
      return search(node->left, key);
    return search(node->right, key);
  }

  void remove(int key) { root = remove(root, key); }
  Node* remove(Node* node, int key) {
    if (!node)
      return nullptr;
    if (key < node->key)
      node->left = remove(node->left, key);
    else if (key > node->key)
      node->right = remove(node->right, key);
    else {
      if (node->is_leaf()) {
        delete node;
        return nullptr;
      }
      if (node->left == nullptr) {
        Node* t = node->right;
        delete node;
        return t;
      }
      if (node->right == nullptr) {
        Node* t = node->left;
        delete node;
        return t;
      }
      Node* succ = node->right;
      while (succ->left)
        succ = succ->left;
      node->key = succ->key;
      node->data = succ->data;
      node->right = remove(node->right, succ->key);
    }
    return node;
  }

  void show() {
    show(root);
    cout << endl;
  }
  void show(Node* n) {
    if (!n)
      return;
    show(n->left);
    cout << n->data << " | ";
    show(n->right);
  }
};

int main() {
  BSTree tree;
  tree.insert(50, 50);
  tree.insert(30, 30);
  tree.insert(20, 20);
  tree.insert(10, 10);
  tree.insert(80, 80);
  tree.insert(90, 90);
  tree.insert(60, 60);

  cout << "Árvore (in-order) após inserções iterativas:\n";
  tree.show();

  cout << "\nRemovendo 20 e mostrando:\n";
  tree.remove(20);
  tree.show();

  return 0;
}
