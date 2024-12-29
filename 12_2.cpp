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

void dfs(int r, int c, int &area, int &sides, vector<vector<int>> &nums, vector<vector<bool>> &vis) {
  vis[r][c] = true;
  area++;

  auto good = [&](pair<int, int> dir) {
    int r2 = r + dir.first;
    int c2 = c + dir.second;
    return is_valid(r2, c2, nums) && nums[r2][c2] == nums[r][c];
  };

  for (int i = 0; i < 4; i++) {
    pair<int, int> dir = directions[i];
    pair<int, int> dir2 = directions[(i + 1) % 4];
    if (!good(dir) && !good(dir2)) {
      sides++;
    }
    if (good(dir) && good(dir2) && !good(make_pair(dir.first + dir2.first, dir.second + dir2.second))) {
      sides++;
    }
  }

  for (pair<int, int> dir : directions) {
    int r2 = r + dir.first;
    int c2 = c + dir.second;
    if (good(dir) && !vis[r2][c2]) {
      dfs(r2, c2, area, sides, nums, vis);
    }
  }
}

int main() {
  long long answer = 0;
  vector<string> input = read_strings("12_1");
  vector<vector<int>> nums;
  vector<vector<bool>> visited;

  for (int r = 0; r < input.size(); r++) {
    vector<int> temp(input[0].size());
    vector<bool> temp_v(input[0].size(), false);
    for (int c = 0; c < input[0].size(); c++) {
      int curr = input[r][c] - 'A' + 1;
      temp[c] = curr;
    }
    nums.push_back(temp);
    visited.push_back(temp_v);
  }

  for (int r = 0; r < nums.size(); r++) {
    for (int c = 0; c < nums[0].size(); c++) {
      if (!visited[r][c]) {
        int area = 0;
        int sides = 0;
        dfs(r, c, area, sides, nums, visited);
        answer += area * sides;
      }
    }
  }

  cout << answer << endl;
}
