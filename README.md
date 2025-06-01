# Lista de tarefas

## Como rodar

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
Ou se vc estiver no winodws pode simplesmente rodar o arquivo `tasks.exe` localizado na raiz do projeto
