# Define o requisito mínimo do CMake
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(main CXX)

# Define o padrão de C++ que queremos usar
set(CMAKE_CXX_STANDARD 17)

# Inclui todos os diretórios onde há headers
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/list
    ${CMAKE_SOURCE_DIR}/src/stack
    ${CMAKE_SOURCE_DIR}/src/types
)

# Adiciona o diretório src ao projeto
add_executable(main
  src/main.cpp
  src/list/List.cpp
  src/stack/Stack.cpp
)
