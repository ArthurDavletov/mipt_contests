#ifndef MAIN_TEST_H
#define MAIN_TEST_H

// IDE ругается, что не существует данного файла. Пока не знаю, как исправить
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "A/index.h"
#include "B/lib.h"

void CheckVector(std::vector<int>&&);
void CheckVector(std::vector<int>&);
void CheckIndex(const std::vector<int>&, int elem);

#endif