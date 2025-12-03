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

  void insert(int data, int key) { return insert(root, data, key); }

  void insert(Node* root, int key, int data) {
    if (root == nullptr) {
      Node* node = new Node;
      node->data = data;
      node->key = key;
      root = node;
      return;
    }

    if (key > root->key) {
      insert(root->right, data, key);
      return;
    }

    if (key < root->key) {
      insert(root->left, data, key);
      return;
    }

    cout << "Duplicate keys are not allowed in BSTree." << endl;
    exit(1);
  }

  Node* search(int key) { return search(root, key); }

  Node* search(Node* root, int key) {
    if (root == nullptr) {
      return nullptr;
    }

    if (key == root->key) {
      return root;
    }

    if (key > root->key) {
      return search(root->right, key);
    }

    if (key < root->key) {
      return search(root->left, key);
    }

    cout << "Unexpected condition encountered during search." << endl;
    exit(1);
  }

  void remove(int key) { return remove(root, key); }

  void remove(Node* root, int key) {
    if (root == nullptr) {
      return;
    }

    if (key > root->key) {
      remove(root->right, key);
      return;
    }

    if (key < root->key) {
      remove(root->left, key);
      return;
    }

    
    if (root -> is_leaf()) {
      delete root;
      return;
    }

    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      root = temp;
      return;
    } 
    
    if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      root = temp;
      return;
    }

    Node* temp = root->right;
    while (temp && temp->left != nullptr) {
      temp = temp->left;
    }

    root->key = temp->key;
    root->data = temp->data;

    remove(root->right, temp->key);
  }

  void show() { return show(root); }

  void show(Node* root) {
    if (root == nullptr)
      return;

    show(root->left);
    cout << root->data << " | ";
    show(root->right);
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

  tree.show();

  return 0;
}
