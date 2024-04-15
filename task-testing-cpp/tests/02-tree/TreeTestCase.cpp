#include "TreeTestCase.h"

namespace fs = std::filesystem;

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
  fs::create_directories("test/1/100/");
  fs::create_directories("test/2/200/");
  std::ofstream("test/test.txt").close();
  std::ofstream("test/1/test.py").close();
  std::ofstream("test/2/file.cpp").close();
}

void TreeTestCase::TearDownTestSuite() {
  fs::remove_all("test/");
}

TEST_F(TreeTestCase, PathNotExists) {
  std::string path = std::to_string(rand());
  while (fs::exists(path)) {
    path = std::to_string(rand());
  }
  ASSERT_THROW(GetTree(path, true), std::invalid_argument);
}

TEST_F(TreeTestCase, InvalidPath) {
  std::string file_path = "test/test.txt";
  ASSERT_THROW(GetTree(file_path, true), std::invalid_argument);
}

TEST_F(TreeTestCase, DirsOnlyTrue) {
  FileNode root = GetTree("test/", true);
  RecursiveCheck(root, "test", true);
}

TEST_F(TreeTestCase, DirsOnlyFalse) {
  FileNode root = GetTree("test/", false);
  RecursiveCheck(root, "test", false);
}

TEST_F(TreeTestCase, FilterEmptyDirs) {
  FileNode root = GetTree("test/", false);
  FilterEmptyNodes(root, "test/");
  ASSERT_TRUE(!AnyEmptyDirectories("test/"));
}

TEST_F(TreeTestCase, RemoveCurrentFolder) {
  fs::create_directories("test/100");
  FileNode root = GetTree("test/100", true);
  ASSERT_THROW(FilterEmptyNodes(root, "."), std::runtime_error);
}

TEST_F(TreeTestCase, FileNodeEqCheck) {
  const FileNode first = GetTree("test/", true);
  const FileNode second = GetTree("test/", true);
  ASSERT_EQ(first, second);
}