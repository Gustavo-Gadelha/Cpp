#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
  Node* prev = nullptr;
};

struct LinkedList {
  Node* head = nullptr;

  void insert(int position, int data) {
    Node* node = new Node;
    node->data = data;

    if (head == nullptr) {
      head = node;
      return;
    }

    if (position == 0) {
      node->next = head;
      head->prev = node;
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
    node->prev = current;

    if (current->next) {
      current->next->prev = node;
    }

    current->next = node;
  }

  void append(int data) {
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
    node->prev = current;
  }

  int size() {
    int counter = 0;
    Node* node = head;
    while (node) {
      ++counter;
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
    cout << "| Previous: " << node->prev << endl;
    cout << "| Next: " << node->next << endl;
    node = node->next;
  }

  cout << "Size of list: " << list.size() << endl;
  return 0;
}
