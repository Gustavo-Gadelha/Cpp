#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
  Node* prev = nullptr;
};

struct DoublyLinkedList {
  Node* head = nullptr;

  void insert(int position, int data) {
    Node* node = new Node;
    node->data = data;

    if (head == nullptr) {
      head = node;
      return;
    }

    if (position < 1) {
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
  DoublyLinkedList list;

  for (int i = 0; i < 50; i++) {
    list.append(i);
  }

  list.insert(0, 1);

  Node* node = list.head;
  int max = list.head->data;
  while (node) {
    if (node->data > max) {
      max = node->data;
    }

    node = node->next;
  }

  cout << "Max value in the list: " << max << endl;
  return 0;
}
