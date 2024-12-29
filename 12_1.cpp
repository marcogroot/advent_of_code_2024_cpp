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

void dfs(int r, int c, int &area, int &per, long long &answer, vector<vector<int>> &nums) {
  int curr = nums[r][c];
  area++;

  long long adj = 0;
  for (auto &dir : directions) {
    int next_r = r + dir.first;
    int next_c = c + dir.second;
    if (is_valid(next_r, next_c, nums)) {
      int next = nums[next_r][next_c];
      if (next == curr || -next == curr) {
        adj++;
      }
    }
  }

  per += (4 - adj);

  if ((per * area) > answer) {
    answer = (per * area);
    char temp = 'A' + curr - 1;
  }
  nums[r][c] *= -1;

  for (auto &dir : directions) {
    int next_r = r + dir.first;
    int next_c = c + dir.second;
    if (is_valid(next_r, next_c, nums)) {
      int next = nums[next_r][next_c];
      if (next == curr) {
        dfs(next_r, next_c, area, per, answer, nums);
      }
    }
  }

  return;
}

int main() {
  long long answer = 0;
  vector<string> input = read_strings("12");
  vector<vector<int>> nums;

  for (int r = 0; r < input.size(); r++) {
    vector<int> temp(input[0].size());
    for (int c = 0; c < input[0].size(); c++) {
      int curr = input[r][c] - 'A' + 1;
      temp[c] = curr;
    }
    nums.push_back(temp);
  }

  print(nums);
  for (int r = 0; r < nums.size(); r++) {
    for (int c = 0; c < nums[0].size(); c++) {
      if (nums[r][c] >= 0) {
        int per = 0;
        int area = 0;
        long long temp = 0;
        dfs(r, c, per, area, temp, nums);
        answer += temp;
      }
    }
  }

  print(nums);
  cout << answer << endl;
}
