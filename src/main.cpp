#include <iostream>
#include <string>
#include "./list/List.h"
#include "./stack/Stack.h"

using namespace std;

List taskList;
Stack undoStack;

void createTask() {
    char name[100];
    int priority, time;

    cout << endl << "==== Adicionar Tarefa ====" << endl;
    cout << "Nome da tarefa: ";
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    cout << "Prioridade (1 = Alta, 2 = Media, 3 = Baixa): ";
    scanf("%d", &priority);
    cout << "Tempo estimado (minutos): ";
    scanf("%d", &time);
    getchar();

    taskList.insertTask(name, priority, time);
    cout << "Tarefa adicionada com sucesso!" << endl << endl;
}

void executeTask() {
    Task* executeTask = taskList.remove();
    cout << executeTask->name << endl;
    undoStack.push(executeTask);
}

void desfazerRemocao() {
    Task* executeTask = undoStack.pop();
    cout << executeTask->name << endl;
    taskList.push(executeTask);
}

int main() {
    int opcao;
    do {
        cout << endl << "==== GERENCIADOR DE TAREFAS =====" << endl;
        cout << "1. Adicionar tarefa" << endl;
        cout << "2. Listar tarefas" << endl;
        cout << "3. Execute Task" << endl;
        cout << "4. Desfazer" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: createTask(); break;
            case 2: taskList.print(); break;
            case 3: executeTask(); break;
            case 4: desfazerRemocao(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
