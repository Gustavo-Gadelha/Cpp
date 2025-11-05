#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
};

struct LinkedList {
  Node* head = nullptr;

  void insert(int position, int data) {
    Node* node = new Node;
    node->data = data;

    if (head == nullptr || position < 1) {
      node->next = head;
      head = node;
      return;
    }

    int index = 1;
    Node* current = head;
    while (current->next && index < position - 1) {
      current = current->next;
      ++index;
    }

    node->next = current->next;
    current->next = node;
  }

  void append(int& data) {
    Node* node = new Node;
    node->data = data;

    if (head == nullptr) {
      head = node;
      return;
    }

    Node* current = head;
    while (current->next) {
      current = current->next;
    }

    current->next = node;
  }

  int size() {
    int counter = 0;

    Node* node = head;
    while (node) {
      counter++;
      node = node->next;
    }

    return counter;
  }
};

int main() {
  LinkedList list;

  for (int i = 0; i < 10; i++) {
    list.append(i);
  }

  list.insert(0, 100);

  Node* node = list.head;
  while (node) {
    cout << "Node (" << node << ") stores " << node->data << endl;
    cout << "| Next: " << node->next << endl;
    node = node->next;
  }

  cout << "Size of list: " << list.size() << endl;

  return 0;
}