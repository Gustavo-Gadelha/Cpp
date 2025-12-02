#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  Node* left = nullptr;
  Node* right = nullptr;

  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

struct Tree {
  Node* root = nullptr;

  void inorder() {
    stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
      while (current != nullptr) {
        stack.push(current);
        current = current->left;
      }

      current = stack.top();
      stack.pop();

      cout << current->data << " | ";
      current = current->right;
    }
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

  tree.inorder();

  return 0;
}
