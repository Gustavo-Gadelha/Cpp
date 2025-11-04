#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next = nullptr;
};

struct FixedStack {
  Node* top = nullptr;
  int cap = 5;
  int size = 0;

  void push(int data) {
    if (isFull()) {
      return;
    }

    Node* node = new Node;
    node->data = data;
    node->next = top;

    top = node;
    size++;
  }

  int pop() {
    if (isEmpty()) {
      return -1;
    }

    Node* node = top;
    int data = top->data;
    top = top->next;
    
    delete node;
    size--;
    
    return data;
  }

  int peek() { return isEmpty() ? -1 : top->data; }

  bool isEmpty() { return (top == nullptr); }

  bool isFull() { return size >= cap; }

  int current_size() { return size; }

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
  FixedStack stack;

  cout << "isFull? " << stack.isFull() << endl;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);
  
  cout << "After 5 pushes: ";
  stack.show();
  
  cout << "isFull? " << stack.isFull() << endl;
  stack.push(60);  
  
  cout << "After trying to push(60): ";
  stack.show();
  
  cout << "peek: " << stack.peek() << endl;
  cout << "pop:  " << stack.pop() << endl;
  cout << "After poping a node: ";
  stack.show();

  return 0;
}
