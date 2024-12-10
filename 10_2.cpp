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

void dfs(int r, int c, long long &answer, vector<vector<int>> &nums) {
  int curr = nums[r][c];
  if (curr == 9) {
    answer++;
    return;
  }

  for (auto &dir : directions) {
    int next_r = r + dir.first;
    int next_c = c + dir.second;
    if (is_valid(next_r, next_c, nums)) {
      int next = nums[next_r][next_c];
      if ((curr + 1) == next) {
        dfs(next_r, next_c, answer, nums);
      }
    }
  }

  return;
}

int main() {
  long long answer = 0;
  vector<string> input = read_strings("10");
  vector<vector<int>> nums;

  vector<pair<int, int>> starts;
  for (int r = 0; r < input.size(); r++) {
    vector<int> temp(input[0].size());
    for (int c = 0; c < input[0].size(); c++) {
      int curr = input[r][c] - '0';
      temp[c] = curr;
      if (curr == 0) {
        starts.push_back({r, c});
      }
    }
    nums.push_back(temp);
  }

  for (auto &start : starts) {
    dfs(start.first, start.second, answer, nums);
  }

  print(nums);
  cout << answer << endl;
}
