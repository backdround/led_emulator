#!/bin/bash
# Это файл сборки и запуска приложения.

set -o errexit

# Переход в директорию для сборки.
# В этой директории хранятся временные файлы.
DESTDIR="$(dirname "$0")/build"
mkdir -p "$DESTDIR"
cd "$DESTDIR"

# Сборка проекта.
cmake .. && cmake --build . -j5
