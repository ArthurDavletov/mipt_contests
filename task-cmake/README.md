# task-cmake

Сортировка выбором

## Структура файлов

* task-cmake/
  * A/
    * preparing.py
  * B/
    * CMakeLists.txt
    * lib.cpp
    * lib.h
  * C/
    * main.cpp
    * main.h
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
cmake ../B/CMakeLists.txt
make Makefile
```

Или одной командой:

```sh
cd task-cmake && mkdir build && cd build && cmake .. && make Makefile```
