#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> read_ints(std::string file_name);

std::vector<std::string> read_strings(std::string file_name);

void print(const std::vector<int> &v);

void print(const std::vector<std::vector<int>> &v);

void print(const std::vector<std::string> &v);

void print(const std::unordered_set<int> &v);

void print(const std::unordered_map<int, int> &m);

void print(const std::unordered_map<int, std::unordered_set<int>> &m);

void print(const std::unordered_map<int, std::vector<int>> &m);

std::vector<int> string_to_vector(const std::string &str);

bool is_valid(int r, int c, const std::vector<std::vector<int>> &input);

bool is_valid(int r, int c, const std::vector<std::string> &input);

#endif
