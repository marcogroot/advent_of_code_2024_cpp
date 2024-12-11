#include "util.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int repetitions = 75;
long long dfs(long long curr, int blinks_left, vector<unordered_map<long, long>> &dp) {
  if (blinks_left == 0) {
    return 1;
  }

  if (dp[blinks_left].count(curr) != 0) {
    return dp[blinks_left][curr];
  }

  int new_blinks_left = blinks_left - 1;
  if (curr == 0) {
    return dp[blinks_left][curr] = dfs(curr + 1, new_blinks_left, dp);
  } else if (to_string(curr).size() % 2 == 0) {
    string curr_string = to_string(curr);
    int len = curr_string.size() / 2;
    long long left = stoll(curr_string.substr(0, len));
    long long right = stoll(curr_string.substr(len, len));
    return dp[blinks_left][curr] = dfs(left, new_blinks_left, dp) + dfs(right, new_blinks_left, dp);
  } else {
    return dp[blinks_left][curr] = dfs((curr * 2024), new_blinks_left, dp);
  }
}
int main() {
  string input = read_strings("11")[0];
  istringstream iss(input);
  vector<long long> nums;
  while (iss.good()) {
    int temp;
    iss >> temp;
    nums.push_back(temp);
  }

  vector<unordered_map<long, long>> dp(repetitions + 1);

  long long answer = 0;
  vector<long long> temp;
  for (int j = 0; j < nums.size(); j++) {
    long long curr = nums[j];
    dfs(curr, repetitions, dp);
  }

  for (long long &num : nums) {
    answer += dp[repetitions][num];
  }
  // for (int i = 0; i < dp.size(); i++) {
  //   cout << "LAYER " << i << " -----------------------" << endl;
  //   for (auto &y : dp[i]) {
  //     cout << y.first << " " << y.second << endl;
  //   }
  // }
  // print(nums);
  cout << answer << endl;
}
