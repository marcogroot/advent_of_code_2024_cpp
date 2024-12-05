#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <util.h>
#include <vector>

std::vector<std::string> read_strings(std::string file_name) {
  std::string text;
  std::ifstream file_read("files/" + file_name + ".txt");
  std::vector<std::string> f;

  while (getline(file_read, text)) {
    f.emplace_back(text);
  }

  if (f.empty())
    std::cout << "Empty input" << std::endl;
  if (f[f.size() - 1].empty()) {
    f.pop_back();
  }
  file_read.close();
  return f;
}

std::vector<int> read_ints(std::string file_name) {
  std::string text;
  std::ifstream file_read("files/" + file_name + ".txt");
  std::vector<int> f;

  while (getline(file_read, text)) {
    f.emplace_back(stoi(text));
  }

  if (f.empty())
    std::cout << "Empty input" << std::endl;
  file_read.close();
  return f;
}

void print(const std::vector<int> &v) {
  if (v.empty()) {
    std::cout << "empty vector" << std::endl;
    return;
  }
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return;
}

void print(const std::vector<std::vector<int>> &v) {
  if (v.empty()) {
    std::cout << "empty vector" << std::endl;
    return;
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      std::cout << v[i][j] << " ";
    }
    std::cout << "\n";
  }
  return;
}

void print(const std::unordered_set<int> &v) {
  if (v.empty()) {
    std::cout << "empty vector" << std::endl;
    return;
  }

  for (auto &a : v) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  return;
}

void print(const std::vector<std::string> &v) {
  if (v.empty()) {
    std::cout << "empty vector" << std::endl;
    return;
  }
  for (std::string x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return;
}

void print(const std::unordered_map<int, std::unordered_set<int>> &m) {
  for (auto &a : m) {
    std::cout << a.first << ": ";
    for (int x : a.second) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}

void print(const std::unordered_map<int, std::vector<int>> &m) {
  for (auto &a : m) {
    std::cout << a.first << ": ";
    for (int x : a.second) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}

void print(const std::unordered_map<int, int> &m) {
  for (auto &a : m) {
    std::cout << a.first << ": " << a.second << std::endl;
  }
}

std::vector<int> string_to_vector(const std::string &str) {
  std::vector<int> result;
  std::stringstream ss(str);
  std::string item;

  while (std::getline(ss, item, ',')) {
    int value;
    if (std::stringstream(item) >> value) {
      result.push_back(value);
    }
  }

  return result;
}
