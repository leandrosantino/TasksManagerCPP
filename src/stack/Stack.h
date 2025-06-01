#pragma once

#include <iostream>
#include <Task.h>
#include <Node.h>

class Stack {
  private:
    Node *startNode, *endNode;

  public:
    Stack();
    void push(Task* task);
    Task* pop();

};
