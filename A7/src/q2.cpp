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

  int peek() { return isEmpty() ? -1 : top->data; }

  bool isEmpty() { return (top == nullptr); }

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

void insertAtBottom(Stack& stack, int data) {
  if (stack.isEmpty()) {
    stack.push(data);
    return;
  }
  int top = stack.pop();
  insertAtBottom(stack, data);
  stack.push(top);
}

void reverse(Stack& stack) {
  if (stack.isEmpty()) return;
  int top = stack.pop();
  reverse(stack);
  insertAtBottom(stack, top);
}

int main() {
  Stack stack;
  for (int i = 1; i <= 7; ++i) {
    stack.push(i);
  }

  cout << "Before: ";
  stack.show();

  reverse(stack);

  cout << "After:  ";
  stack.show();

  return 0;
}
