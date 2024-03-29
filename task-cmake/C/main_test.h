#ifndef MAIN_TEST_H
#define MAIN_TEST_H

// IDE ругается, что не существует данного файла. Пока не знаю, как исправить
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "../B/lib.h"
#include "../A/index.h"

void CheckVector(std::vector<int>&&);
void CheckVector(std::vector<int>&);
void CheckIndex(const std::vector<int>&, int elem);

#endif