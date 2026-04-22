#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

#include "Tree.h"

namespace fs = std::filesystem;

fs::path GenerateNotExistDirName(const std::string& prefix = "");

void RecursiveCheck(const FileNode&, const fs::path&, bool);

class TreeTestCase : public ::testing::Test {
 public:
  TreeTestCase() = default;
  virtual ~TreeTestCase() = default;
  static void SetUpTestSuite();
  static void TearDownTestSuite();
  static fs::path test_dir_;
};


