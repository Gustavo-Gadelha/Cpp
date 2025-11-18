#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
};

struct Queue {
  Node* front = nullptr;
  Node* rear = nullptr;

  void enqueue(int data) {
    Node* node = new Node;
    node->data = data;

    if (front == nullptr) {
      front = node;
      rear = node;
    } else {
      rear->next = node;
      rear = node;
    }
  }

  int dequeue() {
    if (isEmpty()) {
      return -1;
    }

    if (front == rear) {
      rear = nullptr;
    }

    Node* node = front;
    int data = front->data;
    front = front->next;

    delete node;
    return data;
  }

  int peek() { return isEmpty() ? -1 : front->data; }

  bool isEmpty() { return front == nullptr; }

  int size() {
    if (isEmpty()) {
      return 0;
    }

    int count = 0;
    Node* current = front;
    while (current) {
      count++;
      current = current->next;
    }

    return count;
  }

  void show() {
    Node* current = front;

    cout << ">| ";
    while (current) {
      cout << current->data << " | ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  Queue queue;

  for (int i = 0; i < 20; ++i) {
    queue.enqueue(i);
  }

  cout << "After pushing 20 elements:" << endl;
  queue.show();

  for (int j = 0; j < 8; ++j) {
    int data = queue.dequeue();
    cout << "Popped: " << data << endl;
  }

  cout << "After poping 8 elements:" << endl;
  queue.show();

  return 0;
}