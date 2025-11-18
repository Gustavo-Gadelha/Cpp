#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
};

struct Stack {
  Node* top = nullptr;

  void push(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = top;

    top = node;
  }

  int pop() {
    if (isEmpty()) {
      return -1;
    }

    Node* node = top;
    int data = top->data;
    top = top->next;

    delete node;
    return data;
  }

  int peek() {
    return isEmpty() ? -1 : top->data;
  }

  bool isEmpty() {
    return (top == nullptr);
  }

  int size() {
    int counter = 0;
    Node* current = top;

    while (current) {
      counter++;
      current = current->next;
    }

    return counter;
  }

  void show() {

    
    Node* current = top;

    cout << "| ";
    while (current) {
      cout << current->data << " | ";
      current = current->next;
    }

    cout << endl;
  }
};

int main() {
  Stack stack;

  for (int i = 0; i < 20; i++) {
    stack.push(i);
  }

  stack.show();

  return 0;
}