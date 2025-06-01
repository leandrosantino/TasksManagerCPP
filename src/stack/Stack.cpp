#include "./Stack.h"


Stack::Stack(): startNode(NULL), endNode(NULL) {}

// Adiciona No inicio
void Stack::push(Task* task){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) return;

  newNode->value = task;
  newNode->prev = NULL;
  newNode->next = Stack::startNode;

  if (Stack::startNode)
    Stack::startNode->prev = newNode;
  else
    Stack::endNode = newNode;

  Stack::startNode = newNode;
}

//Remove do inicio
Task* Stack::pop(){
  if(!Stack::startNode) return NULL;

  Node* temp = Stack::startNode;
  Stack::startNode = temp->next;

  if(Stack::startNode)
    Stack::startNode->prev = NULL;
  else
    Stack::endNode = NULL;

  Task* removed = temp->value;
  free(temp);
  return removed;
}

