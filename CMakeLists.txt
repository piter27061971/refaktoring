cmake_minimum_required(VERSION 3.10)
project(Task_4) 

#Добавление директории Catch2
add_subdirectory(./Catch2 Catch2-build)

#Установка переменной со списком исходников для тестового исполняемого файла
set (SOURCES_TEST_EXE main_test.cpp shape.cpp)	#transform.cpp
set (HEADERS_TEST_EXE shape.h)					#transform.h

#Создание исполняемого файла с именем #Новое Название проекта
add_executable(Task_4_test ${SOURCES_TEST_EXE} ${HEADERS_TEST_EXE})

#Линковка программы с библиотекой catch2 с #Новое Название проекта
target_link_libraries(Task_4_test PRIVATE Catch2::Catch2)