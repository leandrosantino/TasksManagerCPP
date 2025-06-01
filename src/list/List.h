#pragma once

#include <iostream>
using namespace std;

typedef struct Node {
  struct Task *value;
  struct Node *prev, *next;
} Node;

typedef struct Task {
  char name[100];
  int priority;
  int time;
} Task;

class List {
  private:
    Node *startNode, *endNode;
    int size;

  public:
  List();
  void insert(Task *task);
  void print();
  Task* removeFrist();
  int isEmpty();


};


