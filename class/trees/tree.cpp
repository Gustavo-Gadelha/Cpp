#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left = nullptr;
  Node* right = nullptr;

  bool is_leaf() { return (left == nullptr && right == nullptr); }

  void left_is(int data) {
    if (left != nullptr) {
      exit(1);
    }
    left = new Node{data, nullptr, nullptr};
  }

  void right_is(int data) {
    if (right != nullptr) {
      exit(1);
    }
    right = new Node{data, nullptr, nullptr};
  }
};

struct Tree {
  Node* root = nullptr;

  void inorder(Node* root) {
    if (root == nullptr)
      return;

    inorder(root->left);
    cout << "Data: " << root->data << endl;
    inorder(root->right);
  }

  void preorder(Node* root) {
    if (root == nullptr)
      return;

    cout << "Data: " << root->data << endl;
    preorder(root->left);
    preorder(root->right);
  }

  void postorder(Node* root) {
    if (root == nullptr)
      return;

    postorder(root->left);
    postorder(root->right);
    cout << "Data: " << root->data << endl;
  }
};

int main() {
  Node* root = new Node{1, nullptr, nullptr};
  root->left_is(2);
  root->left->left_is(4);
  root->left->right_is(5);
  root->right_is(3);
  root->right->left_is(6);
  root->right->right_is(7);

  Tree tree;
  tree.root = root;

  tree.inorder(tree.root);

  return 0;
}
