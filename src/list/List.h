#pragma once

#include <iostream>
#include <cstring>
#include <Task.h>
#include <Node.h>

using namespace std;

class List {
  private:
    Node *startNode, *endNode;
    int size;

  public:
    List();
    void append(Task *task);
    void push(Task* task);
    Task* remove();
    void print();
    int isEmpty();
    void insertTask(const char name[100], int priority, int time);
};


