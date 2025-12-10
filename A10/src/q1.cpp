#include <iostream>
#include <string>

using namespace std;

struct Student {
  string name;
  int age;
  double grade;
};

struct Node {
  Student data;
  int key;
  Node* left = nullptr;
  Node* right = nullptr;
  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

struct BSTree {
  Node* root = nullptr;

  void insert(const Student& data, int key) { root = insert(root, data, key); }

  Node* insert(Node* node, const Student& data, int key) {
    if (node == nullptr) {
      Node* n = new Node();
      n->data = data;
      n->key = key;
      return n;
    }
    if (key < node->key) {
      node->left = insert(node->left, data, key);
    } else if (key > node->key) {
      node->right = insert(node->right, data, key);
    } else {
      cout << "Chave duplicada não permitida: " << key << endl;
      exit(1);
    }
    return node;
  }

  Node* search(int key) { return search(root, key); }
  Node* search(Node* node, int key) {
    if (node == nullptr)
      return nullptr;
    if (key == node->key)
      return node;
    if (key < node->key)
      return search(node->left, key);
    return search(node->right, key);
  }

  void remove(int key) { root = remove(root, key); }
  Node* remove(Node* node, int key) {
    if (node == nullptr)
      return nullptr;
    if (key < node->key) {
      node->left = remove(node->left, key);
    } else if (key > node->key) {
      node->right = remove(node->right, key);
    } else {
      // encontramos
      if (node->is_leaf()) {
        delete node;
        return nullptr;
      }
      if (node->left == nullptr) {
        Node* tmp = node->right;
        delete node;
        return tmp;
      } else if (node->right == nullptr) {
        Node* tmp = node->left;
        delete node;
        return tmp;
      } else {
        Node* succ = node->right;
        while (succ->left)
          succ = succ->left;
        node->key = succ->key;
        node->data = succ->data;
        node->right = remove(node->right, succ->key);
      }
    }
    return node;
  }

  void show() {
    show(root);
    cout << endl;
  }
  void show(Node* node) {
    if (!node)
      return;
    show(node->left);
    cout << "[" << node->key << ": " << node->data.name << "] | ";
    show(node->right);
  }
};

int main() {
  BSTree tree;

  Student s1{"Alice", 20, 8.5};
  Student s2{"Bruno", 21, 7.0};
  Student s3{"Carla", 19, 9.2};
  Student s4{"Diego", 22, 6.8};
  Student s5{"Eva", 20, 8.9};

  tree.insert(s1, 50);
  tree.insert(s2, 30);
  tree.insert(s3, 20);
  tree.insert(s4, 80);
  tree.insert(s5, 60);

  cout << "Em-ordem (in-order) da árvore de alunos:\n";
  tree.show();

  cout << "\nBuscando chave 60:\n";
  Node* found = tree.search(60);
  if (found)
    cout << "Encontrado: " << found->data.name
         << ", nota: " << found->data.grade << endl;
  else
    cout << "Não encontrado.\n";

  cout << "\nRemovendo chave 30 e mostrando árvore:\n";
  tree.remove(30);
  tree.show();

  return 0;
}
