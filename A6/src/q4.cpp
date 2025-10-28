#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
  Node* prev = nullptr;
};

Node* split(Node* head) {
  if (!head || !head->next) return nullptr;

  Node* slow = head;
  Node* fast = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node* second = slow->next;
  slow->next = nullptr;
  if (second) second->prev = nullptr;
  return second;
}

Node* merge(Node* left, Node* right) {
  if (!left) {
    return right;
  }
  if (!right) {
    return left;
  }

  if (left->data <= right->data) {
    left->next = merge(left->next, right);
    if (left->next) {
      left->next->prev = left;
    }
    left->prev = nullptr;
    return left;
  } else {
    right->next = merge(left, right->next);
    if (right->next) {
      right->next->prev = right;
    }
    right->prev = nullptr;
    return right;
  }
}

Node* mergeSort(Node* head) {
  if (!head || !head->next) {
    return head;
  }

  Node* second = split(head);

  head = mergeSort(head);
  second = mergeSort(second);

  return merge(head, second);
}

struct DoublyLinkedList {
  Node* head = nullptr;

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

  void sort() {
    head = mergeSort(head);
    if (head) head->prev = nullptr;
  }
};

int main() {
  DoublyLinkedList list;

  for (int i = 100; i > 0; --i) {
    list.append(i);
  }

  list.sort();

  Node* node = list.head;
  while (node) {
    cout << "Node (" << node << ") stores " << node->data << endl;
    cout << "| Next: " << node->next << endl;
    cout << "| Previous: " << node->prev << endl;
    node = node->next;
  }

  return 0;
}
