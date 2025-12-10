#include <iostream>
#include <stack>

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
      exit(1);
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
    cout << n->data << "(" << n->key << ") | ";
    show(n->right);
  }
};

bool inorder_next(stack<Node*>& st, Node*& cur, int& out_key) {
  while (cur != nullptr) {
    st.push(cur);
    cur = cur->left;
  }

  if (st.empty()) {
    return false;
  }

  Node* node = st.top();
  st.pop();
  out_key = node->key;

  cur = node->right;
  return true;
}

bool same_set_of_elements(BSTree& A, BSTree& B) {
  stack<Node*> stA, stB;
  Node* curA = A.root;
  Node* curB = B.root;
  int keyA = 0, keyB = 0;
  bool hasA = inorder_next(stA, curA, keyA);
  bool hasB = inorder_next(stB, curB, keyB);

  while (hasA && hasB) {
    if (keyA != keyB)
      return false;
    hasA = inorder_next(stA, curA, keyA);
    hasB = inorder_next(stB, curB, keyB);
  }

  if (hasA != hasB)
    return false;

  return true;
}

int main() {
  BSTree A;
  A.insert(50, 50);
  A.insert(30, 30);
  A.insert(20, 20);
  A.insert(80, 80);
  A.insert(60, 60);

  BSTree B;
  B.insert(60, 60);
  B.insert(20, 20);
  B.insert(80, 80);
  B.insert(30, 30);
  B.insert(50, 50);

  BSTree C;
  C.insert(50, 50);
  C.insert(30, 30);
  C.insert(99, 99);

  cout << "A in-order: ";
  A.show();
  cout << "B in-order: ";
  B.show();
  cout << "C in-order: ";
  C.show();

  cout << "\nA e B têm o mesmo conjunto de elementos? "
       << (same_set_of_elements(A, B) ? "Sim" : "Não") << endl;
  cout << "A e C têm o mesmo conjunto de elementos? "
       << (same_set_of_elements(A, C) ? "Sim" : "Não") << endl;

  return 0;
}
