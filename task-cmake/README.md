# task-cmake

Сортировка выбором

## Структура файлов

Жирным обозначены файлы, которые генерируются после сборки проекта с помощью CMake

* ```task-cmake/```
  * ```A/```
    * ```preparing.py```
    * ***```index.h```***
  * ```B/```
    * ```CMakeLists.txt```
    * ```lib.cpp```
    * ```lib.h```
  * ```C/```
    * ```CMakeLists.txt```
    * ```main_test.cpp```
    * ```main_test.h```
    * ```main.cpp```
    * ```main.h```
    * ```task_A.cpp```
    * ```task_A.h```
    * ```task_B.cpp```
    * ```task_B.h```
  * ***```bin/```***
    * ***```C```***
    * ***```CTest```***
  * ***```build/```***
  * ***```lib/```***
  * ```README.MD```
  * ```CMakeLists.txt```

## Описание каждого файла

### ```A/preparing.py```

Python-скрипт, который генерирует index.h

### ```A/index.h```

Header-файл, который генерируется после запуска сборки проекта. При каждой сборке содержимое перезаписывается файлом из ```A/preparing.py```

### Остальные файлы

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
