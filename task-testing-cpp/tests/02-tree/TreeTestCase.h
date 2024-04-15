#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

#include "Tree.h"

void RecursiveCheck(const FileNode&, bool);

class TreeTestCase : public ::testing::Test {
 public:
  TreeTestCase() = default;
  virtual ~TreeTestCase() = default;
  static void SetUpTestSuite();
  static void TearDownTestSuite();
};


