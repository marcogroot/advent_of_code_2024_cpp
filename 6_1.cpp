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

vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int r, int c, int dir, vector<vector<int>> &vect) {
  vect[r][c] = -1;

  int next_r = r + directions[dir].first;
  int next_c = c + directions[dir].second;

  if (next_r < 0 || next_c < 0)
    return;
  if (next_r >= vect.size() || next_c >= vect[0].size())
    return;

  if (vect[next_r][next_c] == 1) {
    dir++;
    if (dir == 4) {
      dir = 0;
    }
    next_r = r + directions[dir].first;
    next_c = c + directions[dir].second;
    if (next_r < 0 || next_c < 0)
      return;
    if (next_r >= vect.size() || next_c >= vect[0].size())
      return;
    dfs(next_r, next_c, dir, vect);
  } else {
    dfs(next_r, next_c, dir, vect);
  }
}

int main() {
  long long answer = 0;
  vector<string> input = read_strings("6");
  vector<vector<int>> vect;

  int start_r;
  int start_c;
  int dir = 0;

  for (int r = 0; r < input.size(); r++) {
    string s = input[r];
    vector<int> temp(s.size());
    for (int i = 0; i < s.size(); i++) {
      char curr = s[i];
      if (curr == '#') {
        temp[i] = 1;
      } else {
        temp[i] = 0;
      }
      if (curr == '^') {
        start_r = r;
        start_c = i;
      }
    }
    vect.push_back(temp);
  }

  dfs(start_r, start_c, dir, vect);
  for (int r = 0; r < vect.size(); r++) {
    for (int c = 0; c < vect[r].size(); c++) {
      if (vect[r][c] == -1)
        answer++;
    }
  }
  cout << answer << endl;
}
