#include "./Stack.h"


Stack::Stack(): startNode(NULL), endNode(NULL) {}

// Adiciona No inicio
void Stack::push(Task* task){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) return;

  newNode->value = task;
  newNode->prev = NULL;
  newNode->next = this->startNode;

  if (this->startNode)
    this->startNode->prev = newNode;
  else
    this->endNode = newNode;

  this->startNode = newNode;
}

//Remove do inicio
Task* Stack::pop(){
  if(!this->startNode) return NULL;

  Node* temp = this->startNode;
  this->startNode = temp->next;

  if(this->startNode)
    this->startNode->prev = NULL;
  else
    this->endNode = NULL;

  Task* removed = temp->value;
  free(temp);
  return removed;
}

