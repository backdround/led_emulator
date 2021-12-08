# Файл описывающий сборку для текущей директории.

# Функция поиска исходников.
macro(header_directories return_list)
  file(GLOB_RECURSE new_list *.h)
  foreach(file_path ${new_list})
    get_filename_component(dir_path ${file_path} PATH)
    set(dir_list ${dir_list} ${dir_path})
  endforeach()
  list(REMOVE_DUPLICATES dir_list)
  set(${return_list} ${dir_list})
endmacro()


# Получение исходников по паттерну.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS *.h)
header_directories(DIRECTORIES)

# Поиск библиотеки с потоками.
find_package(Threads)

# Создание основной библиотеки (в рамках cmake'а).
add_library(main_lib STATIC ${SOURCES} ${HEADERS})
target_include_directories(main_lib PUBLIC ${DIRECTORIES})
target_link_libraries(main_lib Threads::Threads)


# Создание бинаркика
add_executable(${PROJECT_NAME} main.cpp)

# Линковка библиотеки к бинарнику.
target_link_libraries(${PROJECT_NAME} main_lib)
