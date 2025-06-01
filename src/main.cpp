#include <iostream>
#include <string>
#include <cstring>
#include "./list/List.h"

using namespace std;

List* taskList = new List();

void createTask() {
    char name[100];
    int priority, time;

    printf("Nome da tarefa: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Prioridade (1 = Alta, 2 = Média, 3 = Baixa): ");
    scanf("%d", &priority);
    printf("Tempo estimado (minutos): ");
    scanf("%d", &time);
    getchar();

    struct Task* task = (struct Task*) malloc(sizeof(struct Task));

    if (task == NULL) cout << "Erro ao alocar memória para a tarefa." << endl;

    strcpy(task->name, name);
    task->priority = priority;
    task->time = time;

    taskList->insert(task);
    printf("Tarefa adicionada com sucesso!\n");
}

void removerUltimaTarefa() {
    taskList->removeFrist();
}

void desfazerRemocao() {
}

int main() {
    int opcao;

    cout << "Teste" << taskList->isEmpty() << endl;

    do {
        printf("===== GERENCIADOR DE TAREFAS =====\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Execute Task\n");
        printf("4. Desfazer remoção\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: createTask(); break;

            case 2: taskList->print(); break;

            case 3: removerUltimaTarefa(); break;

            case 4: desfazerRemocao(); break;

            case 0: printf("Saindo...\n"); break;

            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
