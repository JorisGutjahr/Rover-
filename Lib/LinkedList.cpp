#include <stdio.h> //TODO remove printf by std::cout << and this line by
                  //#include <iostream>

typedef unsigned int uint;
template <typename T>
class Node {
public:
  Node<T> (){};
  T value;
  Node<T> *next;
};


template <typename T>
class List {
private:
  Node<T> *head;
  Node<T> *tail;
  uint total;
public:
  List(uint length) {
    total = length;
    head = new Node<T>;
    tail = head;
    for(uint i = 1;i < length;i++) {
      tail->next = tail;
      tail = new Node<T>;
    }
  }
  Node<T>* atIndex(uint index) {
    Node<T> *current = head;
    for(int i = 0;i < total;i++) {
      if(i == index) {
        return current;
      }
    }
    return NULL;
  }
  int set(uint index,T v) {
    Node<T> *n = atIndex(index);
    if(n == NULL)
      return 1;
    n->value = v;
    return 0;
  }
  T get(uint index) {
    return atIndex(index)->value;
  }
  void insert(uint index,T newv) {
     Node<T>* new_node = new Node<T>();
     new_node->value = newv;
     Node<T>* next = atIndex(index);
     if(next != NULL)
        new_node->next = next;
     else
        tail = new_node;
     total++;
  }
  void append(T newv) {
    insert(total,newv);
  }
  T pop() {
    T value = head->value;
    head = head->next;
    return value;
  }
};

//Test

int main(void) {
  List<int> l = List<int>(100); //List with length 5
  uint lastNumber = 2;
  for(uint i = 0;i < 99;i++) {
    lastNumber *= lastNumber;
    l.set(i,lastNumber);
    printf("%d\n",l.get(i));
  };
  printf("\n");
  return 0;
}
