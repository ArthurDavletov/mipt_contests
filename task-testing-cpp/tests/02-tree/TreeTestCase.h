//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

#include "Tree.h"

void RecursiveCheck(const FileNode&, bool);

class TreeTestCase : public ::testing::Test {
 public:
  static void SetUpTestSuite();
  static void TearDownTestSuite();
};


