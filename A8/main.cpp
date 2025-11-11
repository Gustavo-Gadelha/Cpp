#include <iostream>

using namespace std;

template <class T>
struct Node {
  T data;
  Node<T>* next = nullptr;
};

template <class T>
struct Queue {
  Node<T>* front = nullptr;
  Node<T>* rear = nullptr;

  void enqueue(T data) {
    Node<T>* node = new Node<T>;
    node->data = data;

    if (rear == nullptr) {
      front = node;
      rear = node;
    } else {
      rear->next = node;
      rear = node;
    }
  }

  T dequeue() {
    if (isEmpty()) {
      exit(1);
    }

    Node<T>* node = front;
    T data = node->data;

    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }

    delete node;
    return data;
  }

  bool isEmpty() { return front == nullptr; }

  int size() {
    if (isEmpty()) {
      return 0;
    }

    int count = 0;
    Node<T>* current = front;
    while (current) {
      count++;
      current = current->next;
    }

    return count;
  }
};

template <class T>
struct LinkedList {
  Node<T>* head = nullptr;
  Node<T>* tail = nullptr;

  void append(T data) {
    Node<T>* node = new Node<T>;
    node->data = data;

    if (head == nullptr) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }

  T pop() {
    if (isEmpty()) {
      exit(1);
    }

    Node<T>* node = head;
    T data = head->data;
    head = head->next;

    delete node;
    return data;
  }

  T remove(int index) {
    if (isEmpty() || index < 0 || index >= size()) {
      exit(1);
    }

    Node<T>* previous = head;
    for (int i = 0; i < index - 1; ++i) {
      previous = previous->next;
    }

    Node<T>* target = previous->next;
    T data = target->data;

    previous->next = target->next;

    delete target;
    return data;
  }

  bool isEmpty() { return head == nullptr; }

  int size() {
    int counter = 0;

    Node<T>* node = head;
    while (node) {
      counter++;
      node = node->next;
    }

    return counter;
  }
};

struct Subject {
  string name;
  int credits;
  LinkedList<string> contents;

  void addContent(string content) { contents.append(content); }

  void removeContent(int index) { contents.remove(index); }

  void showContents(string prefix) {
    Node<string>* node = contents.head;
    while (node) {
      cout << prefix << node->data << endl;
      node = node->next;
    }
  }

  void show(string prefix) {
    cout << prefix << "Disciplina de " << name << " (" << credits << " creditos)"
         << endl;
  }
};

struct Student {
  string name;
  string cpf;
  int age;
  string enrollment;
  LinkedList<Subject> subjects;

  void enroll(Subject subject) { subjects.append(subject); }

  void unenroll(int index) { subjects.remove(index); }

  void showSubjects(string prefix) {
    Node<Subject>* node = subjects.head;
    while (node) {
      node->data.show(prefix);
      node = node->next;
    }
  }

  void show(string subjectPrefix, string contentPrefix) {
    cout << "Aluno: " << name << endl;

    Node<Subject>* node = subjects.head;
    while (node) {
      node->data.show(subjectPrefix);
      node->data.showContents(contentPrefix);
      node = node->next;
    }
  }
};

int main() {
  Queue<Student> queue;

  Subject matematica{"Matematica", 4};
  matematica.addContent("Funcoes");
  matematica.addContent("Derivadas");
  matematica.addContent("Integrais");

  Subject algoritmos{"Algoritmos", 6};
  algoritmos.addContent("Listas ligadas");
  algoritmos.addContent("Filas");

  Subject fisica{"Fisica", 5};
  fisica.addContent("Cinematica");
  fisica.addContent("Termodinamica");

  Student aluna{"Ana Silva", "123.456.789-00", 20, "2025001"};
  aluna.enroll(matematica);
  aluna.enroll(algoritmos);
  aluna.enroll(fisica);
  
  Student aluno{"José Carlos", "321.654.987-00", 50, "2023001"};
  aluno.enroll(algoritmos);

  queue.enqueue(aluna);
  queue.enqueue(aluno);

  cout << endl << "< Dados das disciplinas do aluno >" << endl;
  aluna.showSubjects("| ");

  cout << endl << "< Após cancelar a mátricula em Algoritmos >" << endl;
  aluna.unenroll(1);
  aluna.showSubjects("| ");

  cout << endl << "< Conteúdos da disciplina de Matemática >" << endl;
  matematica.showContents("+ ");

  cout << endl << "< Após adicionar novo conteúdo em Matemática >" << endl;
  matematica.addContent("Equacoes Diferenciais");
  matematica.showContents("+ ");

  cout << endl << "< Após remover o conteúdo Derivadas de Matemática >" << endl;
  matematica.removeContent(1);
  matematica.showContents("+ ");

  Node<Student>* node = queue.front;
  while (node) {
    cout << endl << "< Dados do aluno na fila de atendimento >" << endl;
    node->data.show("| ", "+ ");
    node = node->next;
  }

  return 0;
}
