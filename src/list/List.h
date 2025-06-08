#pragma once

#include <iostream>
#include <cstring>
#include <Task.h>
#include <Node.h>
#include <string>

using namespace std;

class List {
  private:
    Node *startNode, *endNode;
    int size;

  public:
    List();
    //inserir no final
    void append(Task *task);

    //remover do começo
    Task* remove();

    // // inserir no começo;
    void push(Task* task);

    void sortByPriority();
    void sortByTime();
    void sortByName();

    void print();
    int isEmpty();
    void insertTask(const char name[100], int priority, int time);

};


