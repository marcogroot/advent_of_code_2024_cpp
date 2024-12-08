#include "util.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main() {
  long long answer = 0;
  vector<string> input = read_strings("8");

  unordered_map<char, vector<pair<int, int>>> m;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      char curr = input[i][j];
      if (curr != '.') {
        if (m.count(curr) == 0) {
          m[curr] = {{i, j}};
        } else {
          m[curr].push_back({i, j});
        }
      }
    }
  }

  for (auto &x : m) {
    for (int i = 0; i < x.second.size(); i++) {
      for (int j = 0; j < x.second.size(); j++) {
        if (i == j) {
          continue;
        }
        pair<int, int> p1 = x.second[i];
        pair<int, int> p2 = x.second[j];
        int r_diff = p1.first - p2.first;
        int c_diff = p1.second - p2.second;
        int new_r = p1.first + r_diff;
        int new_c = p1.second + c_diff;

        if (is_valid(new_r, new_c, input)) {
          input[new_r][new_c] = '#';
        }
      }
    }
  }

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[0].size(); j++) {
      char curr = input[i][j];
      if (curr == '#') {
        answer++;
      }
    }
  }

  // print(input);
  cout << answer << endl;
}
