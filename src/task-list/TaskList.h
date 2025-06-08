#pragma once

#include <iostream>
#include <cstring>
#include <Task.h>
#include <Node.h>
#include <string>

using namespace std;

class TaskList {
  private:
    Node *startNode, *endNode;
    int size;

  public:
    TaskList();
    //inserir no final
    void append(Task *task);

    //remover do começo
    Task* remove();

    void sortByPriority();
    void sortByTime();
    void sortByName();

    void print();
    int isEmpty();
    void insertTask(const char name[100], int priority, int time);

};


