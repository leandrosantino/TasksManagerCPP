# Lista de tarefas

O projeto implementa uma CLI para gerenciar tarefas escrita completamente em C++.
É um projeto de estudo para a matéria de Estrutura de Dados.

Foi implementado do zero listas encadeadas aplicando os conceitos de `Pilha` e `Fila`. 

## Equipe
- Leandro Santino
- Carolina Fernanda
- Andrey Francisco
- Maria Gabriella

## Como rodar

### Windows

Tenha o MinGW e o CMake instalados

Crie a pasta build na raiz do projeto e mude para ela
```sh
mkdir build
cd build
```
Execute o seguinte comando para configurar o CMake
```sh
cmake -G "MinGW Makefiles" ..
```
Depois rode o seguinte comando para compilar o projeto
```sh
cmake --build .
```
Por fim basta apenas execultar o arquivo main
```sh
./main
```
Ou se você preferir pode simplesmente rodar o arquivo `tasks-win_x86.exe` localizado na raiz do projeto com o seguinte comando 
```sh
./tasks-win_x86.exe
```

### Linux

Tenha o MinGW e o CMake instalados

Na pasta raiz do projeto rode o seguinte comando para compilar e execultar o código
```sh
make && ./main
```

Ou se você preferir pode simplesmente rodar o arquivo `tasks-linux` localizado na raiz do projeto com o seguinte comando 
```sh
./tasks-linux
```