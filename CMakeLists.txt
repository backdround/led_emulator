# Главный файл, описывающий сборку приложений.

cmake_minimum_required(VERSION 3.12.2)
project(app CXX)

# Конфигурация проекта.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Обработка cmake файла из директории src.
add_subdirectory(src)
