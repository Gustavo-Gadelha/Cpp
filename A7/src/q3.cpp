#include <iostream>
using namespace std;

struct Node {
  char data;
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
    if (isEmpty()) return -1;
    Node* node = top;
    int data = top->data;
    top = top->next;
    delete node;
    return data;
  }

  int peek() { return isEmpty() ? -1 : top->data; }

  bool isEmpty() { return top == nullptr; }
};

int main() {
  string text = "Estrutura de Dados em cpp";
  cout << "Before: " << text << endl;

  Stack stack;

  for (int i = 0; i < text.length(); ++i) {
    stack.push(text[i]);
  }

  string result;

  while (not stack.isEmpty()) {
    result += stack.pop();
  }

  cout << "After: " << result << endl;

  return 0;
}
