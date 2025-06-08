#include "List.h"

List::List(): startNode(NULL), endNode(NULL), size(0) {
  this->insertTask("Adicionar nomes no codigo", 2, 7);
  this->insertTask("Iniciar Projeto de Estrutura de dados", 1, 6);
  this->insertTask("Subir Projeto no Github", 1, 5);
  this->insertTask("Abiciar Projeto de Estrutura de dados", 3, 4);
  this->insertTask("Criar mapa mental", 2, 3);
  this->insertTask("Separar as falas", 3, 12);
  this->insertTask("Modificar readme", 1, 1);
}

void List::insertTask(const char name[100], int priority, int time) {
  struct Task* task = (struct Task*) malloc(sizeof(struct Task));
  if (task == NULL) cout << "Erro ao alocar memória para a tarefa." << endl;
  strcpy(task->name, name);
  task->priority = priority;
  task->time = time;
  this->append(task);
}

int List::isEmpty() {
  return this->size == 0;
}

// Insere no Final
void List::append(Task *task) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) {
    cerr << "Memory allocation failed!" << endl;
    return;
  }

  newNode->value = task;
  newNode->prev = this->endNode;
  newNode->next = NULL;

  if(this->endNode)
    this->endNode->next = newNode;
  else
    this->startNode = newNode;

  this->endNode = newNode;
  this->size++;
}

//Remove do inicio
Task* List::remove() {
  if(this->isEmpty()) return NULL;

  Node *temp = this->startNode;
  this->startNode = temp->next;

  if(this->startNode){
    this->startNode->prev = NULL;
  } else {
    this->endNode = NULL;
  }

  this->size--;
  Task* removed = temp->value;
  free(temp);
  return removed;
}

string pad(string str, size_t totalLength, char fillChar = '0', char p = 'l') {
  if (str.length() < totalLength) {
    if(p == 'l') str.insert(0, totalLength - str.length(), fillChar);
    if(p == 'r') str.append(totalLength - str.length(), fillChar);
  }
  return str;
}

void List::print() {
  Node* current = this->startNode;
  cout << endl << "Minhas Tarefas" << endl;

  int maxSize = 0;
  while(current){
    int nameSize = strlen(current->value->name);
    if(maxSize < nameSize) maxSize  = nameSize;
    current = current->next;
  }
  current = this->startNode;
  string line = pad("", maxSize + 30, '-');

  cout << line << endl;
  cout << "| " << pad("Nome", maxSize, ' ', 'r') << " | Prioridade | Tempo(min) | " << endl;
  cout << line << endl;

  while (current) {
    cout
      << "| " << pad(current->value->name, maxSize, ' ', 'r')
      << " |      " << current->value->priority
      << "     |     " << pad(to_string(current->value->time), 2)
      << "     |" << endl;
    current = current->next;
  }
  cout<< line << endl;
}

// Adiciona No inicio
void List::push(Task* task){
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) return;

  newNode->value = task;
  newNode->prev = NULL;
  newNode->next = this->startNode;

  if (this->startNode)
    this->startNode->prev = newNode;
  else
    endNode = newNode;

  this->startNode = newNode;
}

//bubbleSort
void List::sortByPriority() {
  Node* currentI = this->startNode;
  for (int i = 0; i < this->size - 1; i++) {
    Node* currentJ = this->startNode;
    for (int j = 0; j < this->size -i-1; j++ ) {
      if ( currentJ->value->priority > currentJ->next->value->priority ) {
        Task* temp = currentJ->value;
        currentJ->value = currentJ->next->value;
        currentJ->next->value = temp;
      }
      currentJ = currentJ->next;
    }
    currentI = currentI->next;
  }
}

//insertionSort
void List::sortByTime() {
  int i, j;
  Task* key;
  Node* currentI = this->startNode->next;
  while (currentI != NULL) {
    // cout << currentI->value->name << endl;
    key = currentI->value;

    Node* currentJ = currentI->prev;
    while(currentJ != NULL && currentJ->value->time > key->time){
      // cout << "   - " << currentJ->value->name << endl;
      currentJ->next->value = currentJ->value;
      currentJ = currentJ->prev;
    }
    this->startNode->value = key;

    currentI = currentI->next;
  }
}

//selectionSort
void List::sortByName() {
  Task* temp;
  Node* minIndex;
  Node* currentI = this->startNode;

  while (currentI != this->endNode) {
    minIndex = currentI;
    Node* currentJ = currentI->next;
    while(currentJ != NULL){
      if (strcmp(currentJ->value->name, minIndex->value->name) < 0) {
        minIndex = currentJ;
      }
      currentJ = currentJ->next;
    }

    temp = currentI->value;
    currentI->value = minIndex->value;
    minIndex->value = temp;

    currentI = currentI->next;
  }
}
