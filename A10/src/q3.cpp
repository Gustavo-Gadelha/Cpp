#include <iostream>

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

  void insert(int data, int key) { root = insert(root, data, key); }
  Node* insert(Node* node, int data, int key) {
    if (!node) {
      Node* n = new Node();
      n->data = data;
      n->key = key;
      return n;
    }
    if (key < node->key)
      node->left = insert(node->left, data, key);
    else if (key > node->key)
      node->right = insert(node->right, data, key);
    else {
      cout << "Duplicate key\n";
      exit(1);
    }
    return node;
  }

  bool is_bst() {
    int prev = 0;
    bool has_prev = false;
    return is_bst_inorder(root, prev, has_prev);
  }

  bool is_bst_inorder(Node* node, int& prev, bool& has_prev) {
    if (!node)
      return true;
    if (!is_bst_inorder(node->left, prev, has_prev))
      return false;
    if (has_prev) {
      if (node->key <= prev)
        return false;
    }
    prev = node->key;
    has_prev = true;
    return is_bst_inorder(node->right, prev, has_prev);
  }

  void show() {
    show(root);
    cout << endl;
  }

  void show(Node* n) {
    if (!n)
      return;
    show(n->left);
    cout << n->data << "(" << n->key << ") | ";
    show(n->right);
  }
};

Node* make_not_bst() {
  Node* a = new Node();
  a->key = 10;
  a->data = 10;
  Node* b = new Node();
  b->key = 5;
  b->data = 5;
  Node* c = new Node();
  c->key = 15;
  c->data = 15;
  a->left = b;
  a->right = c;
  Node* d = new Node();
  d->key = 12;
  d->data = 12;
  b->left = d;
  return a;
}

int main() {
  BSTree tree;
  tree.insert(50, 50);
  tree.insert(30, 30);
  tree.insert(20, 20);
  tree.insert(10, 10);
  tree.insert(80, 80);
  tree.insert(90, 90);
  tree.insert(60, 60);

  cout << "Árvore (in-order): ";
  tree.show();
  cout << "É BST? " << (tree.is_bst() ? "Sim" : "Não") << endl;

  BSTree bad;
  bad.root = make_not_bst();
  cout << "Árvore inválida é BST? " << (bad.is_bst() ? "Sim" : "Não") << endl;

  return 0;
}
