# task-cmake

Сортировка выбором

## Структура файлов

Жирным обозначены файлы, которые генерируются после сборки проекта с помощью CMake

* task-cmake/
  * A/
    * preparing.py
    * ***index.h***
  * B/
    * CMakeLists.txt
    * lib.cpp
    * lib.h
  * C/
    * main.cpp
    * main.h
  * ***bin/***
    * ***C***
    * ***CTest***
  * ***build/***
  * ***lib/***
  * README.MD
  * CMakeLists.txt

## Описание каждого файла

* preparing.py -- генерирует index.h (пока заглушка)
* /B/CMakeLists.txt -- cmake-лист для сборки библиотеки сортировки
* /CMakeLists.txt -- главный cmake-лист
* lib.cpp и lib.h -- тут содержится функция сортировки
* main.h и main.cpp -- пример работы библиотеки

## Сборка проекта

```sh
cd task-cmake
mkdir build
cd build
cmake ..
make
cd ..
```

Или одной командой:

```sh
cd task-cmake && mkdir build && cd build && cmake .. && make && cd ..
```
