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
  unordered_map<int, vector<int>> m;
  while (!input[i].empty()) {
    int before;
    int after;
    after = stoi(input[i].substr(0, 2));
    before = stoi(input[i].substr(3, 2));

    if (m.count(after) == 0) {
      vector<int> temp = {before};
      m[after] = temp;
    } else {
      m[after].push_back(before);
    }

    i++;
  }

  i++;
  vector<vector<int>> rules;
  while (!input[i].empty()) {
    rules.push_back(string_to_vector(input[i]));
    i++;
  }

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
    if (flag) {
      int middle = rule[(rule.size() / 2)];
      answer += middle;
    }
  }
  cout << answer << endl;
}
