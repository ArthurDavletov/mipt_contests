#ifndef MAIN_TEST_H
#define MAIN_TEST_H

// IDE ругается, что не существует данного файла. Пока не знаю, как исправить
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "../B/lib.h"

void CheckVectors(std::vector<int>&&);
void CheckVectors(std::vector<int>&);

#endif