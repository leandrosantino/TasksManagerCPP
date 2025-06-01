#include "List.h"

List::List(): startNode(NULL), endNode(NULL), size(0) {}

int List::isEmpty() {
  return List::size == 0;
}

void List::insert(Task *task) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) {
    cerr << "Memory allocation failed!" << endl;
    return;
  }

  newNode->value = task;
  newNode->prev = List::endNode;
  newNode->next = NULL;

  if(List::endNode)
    List::endNode->next = newNode;
  else
    List::startNode = newNode;

  List::endNode = newNode;
  List::size++;
}

void List::print() {
  Node *current = List::startNode;
  cout << endl << "Current Tasks:" << endl;
  while (current) {
    cout << "Task: " << current->value->name
         << ", Priority: " << current->value->priority
         << ", Time: " << current->value->time << " min" << endl;
    current = current->next;
  }
  cout << endl;
}

Task* List::removeFrist() {
  if(List::isEmpty()) return NULL;

  Node *temp = List::startNode;
  List::startNode = temp->next;

  if(List::startNode){
    List::startNode->prev = NULL;
  } else {
    List::endNode = NULL;
  }

  free(temp);
  List::size--;
  return temp->value;
}
