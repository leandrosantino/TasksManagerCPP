#include "List.h"


List::List(): startNode(NULL), endNode(NULL), size(0) {
  List::insertTask("Comprar pao", 1, 5);
  List::insertTask("Iniciar Projeto de Estrutura de dados", 1, 5);
  List::insertTask("Subir Projeto no Github", 1, 5);
}

void List::insertTask(const char name[100], int priority, int time) {
  struct Task* task = (struct Task*) malloc(sizeof(struct Task));
  if (task == NULL) cout << "Erro ao alocar memória para a tarefa." << endl;
  strcpy(task->name, name);//
  task->priority = priority;
  task->time = time;
  List::append(task);
}

int List::isEmpty() {
  return List::size == 0;
}

// Insere no Final
void List::append(Task *task) {
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

//Remove do inicio
Task* List::remove() {
  if(List::isEmpty()) return NULL;

  Node *temp = List::startNode;
  List::startNode = temp->next;

  if(List::startNode){
    List::startNode->prev = NULL;
  } else {
    List::endNode = NULL;
  }

  List::size--;
  Task* removed = temp->value;
  free(temp);
  return removed;
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

// Adiciona No inicio
void List::push(Task* task){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) return;

  newNode->value = task;
  newNode->prev = NULL;
  newNode->next = List::startNode;

  if (List::startNode)
    List::startNode->prev = newNode;
  else
    List::endNode = newNode;

  List::startNode = newNode;
}

