#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left = nullptr;
  Node* right = nullptr;

  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

struct Tree {
  Node* root = nullptr;

  void show_even(Node* root) {
    if (root == nullptr)
      return;

    show_even(root->left);
    if (root->data % 2 == 0) {
      cout << "EVEN: " << root->data << endl;
    }
    show_even(root->right);
  }

  void show_odd(Node* root) {
    if (root == nullptr)
      return;

    show_odd(root->left);
    if (root->data % 2 == 1) {
      cout << "ODD: " << root->data << endl;
    }
    show_odd(root->right);
  }
};

int main() {
  Node* n9 = new Node{9, nullptr, nullptr};
  n9->left = new Node{4, nullptr, nullptr};

  Node* n5 = new Node{5, nullptr, nullptr};
  n5->right = n9;

  Node* n6 = new Node{6, nullptr, nullptr};
  n6->left = new Node{5, nullptr, nullptr};
  n6->right = new Node{11, nullptr, nullptr};

  Node* n7 = new Node{7, nullptr, nullptr};
  n7->left = new Node{2, nullptr, nullptr};
  n7->right = n6;

  Node* root = new Node{2, nullptr, nullptr};
  root->left = n7;
  root->right = n5;

  Tree tree;
  tree.root = root;

  tree.show_odd(tree.root);
  cout << endl;
  tree.show_even(tree.root);

  return 0;
}
