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

  void postorder() {
    if (root == nullptr)
      return;

    stack<Node*> result;
    stack<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      Node* current = nodes.top();
      nodes.pop();

      if (current->left)
        nodes.push(current->left);
      if (current->right)
        nodes.push(current->right);

      result.push(current);
    }

    while (!result.empty()) {
      Node* current = result.top();
      result.pop();

      cout << current->data << " | ";
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

  tree.postorder();

  return 0;
}
