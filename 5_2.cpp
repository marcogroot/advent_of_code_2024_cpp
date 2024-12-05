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
  vector<string> input = read_strings("5");

  int i = 0;
  unordered_map<int, unordered_set<int>> m;
  unordered_map<int, unordered_set<int>> reverse_m;
  while (!input[i].empty()) {
    int before;
    int after;
    after = stoi(input[i].substr(0, 2));
    before = stoi(input[i].substr(3, 2));

    if (m.count(after) == 0) {
      unordered_set<int> temp = {before};
      m[after] = temp;
    } else {
      m[after].insert(before);
    }
    i++;
  }

  i++;
  vector<vector<int>> rules;
  while (!input[i].empty()) {
    rules.push_back(string_to_vector(input[i]));
    i++;
  }
  vector<vector<int>> rules_to_fix;
  for (const vector<int> rule : rules) {
    bool flag = true;
    unordered_set<int> temp;
    for (const int x : rule) {
      temp.insert(x);
      for (const int y : m[x]) {
        if (temp.count(y) != 0)
          flag = false;
      }
    }
    if (!flag) {
      rules_to_fix.push_back(rule);
    }
  }

  for (vector<int> &rule : rules_to_fix) {
    vector<int> temp = {rule[0]};
    int pointer = 0;
    for (int i = 1; i < rule.size(); i++) {
      int curr = rule[i];
      int pos = temp.size();
      for (int j = temp.size() - 1; j >= 0; j--) {
        int comp = temp[j];
        if (m.count(curr) && m[curr].count(comp) != 0) {
          pos = j;
        }
        if (m.count(comp) && m[comp].count(curr) != 0) {
          pos = j + 1;
          break;
        }
      }
      temp.insert(temp.begin() + pos, curr);
    }
    int middle = temp[(temp.size() / 2)];
    answer += middle;
  }
  cout << answer << endl;
}
