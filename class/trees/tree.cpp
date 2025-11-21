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
  
  root->left = new Node{2, nullptr, nullptr};
  root->left->left = new Node{4, nullptr, nullptr};
  root->left->right = new Node{5, nullptr, nullptr};

  root->right = new Node{3, nullptr, nullptr};
  root->right->left = new Node{6, nullptr, nullptr};
  root->right->right = new Node{7, nullptr, nullptr};

  Tree tree;
  tree.root = root;

  tree.inorder(tree.root);

  return 0;
}
