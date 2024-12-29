#include "util.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<int> get_xy(const string &input) {
  vector<int> symb_indexes;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '=' || input[i] == ' ' || input[i] == ',') {
      symb_indexes.push_back(i);
    }
  }
  int p1 = stoi(input.substr(symb_indexes[0] + 1, symb_indexes[1] - symb_indexes[0] - 1));
  int p2 = stoi(input.substr(symb_indexes[1] + 1, symb_indexes[2] - symb_indexes[1] - 1));
  int p3 = stoi(input.substr(symb_indexes[3] + 1, symb_indexes[4] - symb_indexes[3] - 1));
  int p4 = stoi(input.substr(symb_indexes[4] + 1));
  return {p1, p2, p3, p4};
}

void print_easter_egg(const std::vector<std::vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      if (v[i][j]) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << "\n";
  }
  return;
}

int main() {
  vector<string> input = read_strings("14");
  const int W = 101;
  const int H = 103;

  for (int frame = 6586; frame <= 6589; frame++) {
    vector<vector<int>> m(H, vector<int>(W, 0));
    for (int i = 0; i < input.size(); i++) {
      vector<int> nums = get_xy(input[i]);
      nums[0] = ((nums[0] + nums[2] * frame) % W + W) % W;
      nums[1] = ((nums[1] + nums[3] * frame) % H + H) % H;
      m[nums[0]][nums[1]] = 1;
    }

    print_easter_egg(m);
  }
}
