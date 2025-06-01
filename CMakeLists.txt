# Define o requisito mínimo do CMake
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(main CXX)

# Define o padrão de C++ que queremos usar
set(CMAKE_CXX_STANDARD 17)

# Adiciona o diretório src ao projeto
add_executable(main src/main.cpp src/list/List.cpp)
