#include "TreeTestCase.h"

namespace fs = std::filesystem;

fs::path TreeTestCase::test_dir_;

fs::path GenerateNotExistDirName(const std::string& prefix) {
  std::string name = "";
  if (!prefix.empty()) {
    name += prefix + "_";
  }
  int r = rand();
  for (; fs::exists(name + std::to_string(r)); r = rand());
  return name + std::to_string(r);
}

void RecursiveCheck(const FileNode& node, const fs::path& relative_path, bool dirs_only) {
  auto path = relative_path / node.name;
  ASSERT_EQ(node.is_dir, fs::is_directory(path));

  if (!fs::is_directory(path)) {
    return;
  }

  int counter = 0;
  for (auto const& child : fs::directory_iterator(path)) {
    if (!dirs_only || child.is_directory()) {
      counter++;
    }
  }

  ASSERT_EQ(counter, node.children.size());

  for (auto const& child : node.children) {
    RecursiveCheck(child, path, dirs_only);
  }
}

bool AnyEmptyDirectories(const fs::path& p) {
  bool flag = false;
  for (auto& child : fs::directory_iterator(p)) {
    if (child.is_directory()) {
      flag = fs::is_empty(child) || AnyEmptyDirectories(child);
    }
  }
  return flag;
}

void TreeTestCase::SetUpTestSuite() {
  test_dir_ = GenerateNotExistDirName("test");
  fs::create_directories(test_dir_ / "1/100/");
  fs::create_directories(test_dir_ / "2/200/");
  std::ofstream(test_dir_ / "test.txt").close();
  std::ofstream(test_dir_ / "1/test.py").close();
  std::ofstream(test_dir_ / "2/file.cpp").close();
}

void TreeTestCase::TearDownTestSuite() {
  fs::remove_all(test_dir_);
}

TEST_F(TreeTestCase, PathNotExists) {
  std::string path = std::to_string(rand());
  while (fs::exists(path)) {
    path = std::to_string(rand());
  }
  ASSERT_THROW(GetTree(path, true), std::invalid_argument);
}

TEST_F(TreeTestCase, InvalidPath) {
  std::string file_path = test_dir_ / "test.txt";
  ASSERT_THROW(GetTree(file_path, true), std::invalid_argument);
}

TEST_F(TreeTestCase, DirsOnlyTrue) {
  FileNode root = GetTree(test_dir_, true);
  RecursiveCheck(root, "", true);
}

TEST_F(TreeTestCase, DirsOnlyFalse) {
  FileNode root = GetTree(test_dir_, false);
  RecursiveCheck(root, "", false);
}

TEST_F(TreeTestCase, FilterEmptyDirs) {
  FileNode root = GetTree(test_dir_, false);
  FilterEmptyNodes(root, test_dir_);
  ASSERT_FALSE(AnyEmptyDirectories(test_dir_));
}

TEST_F(TreeTestCase, RemoveCurrentFolder) {
  fs::create_directories(test_dir_ / "100");
  FileNode root = GetTree(test_dir_ / "100", true);
  ASSERT_THROW(FilterEmptyNodes(root, "."), std::runtime_error);
}

TEST_F(TreeTestCase, FileNodeEqCheck) {
  const FileNode first = GetTree(test_dir_, true);
  const FileNode second = GetTree(test_dir_, true);
  ASSERT_EQ(first, second);
}