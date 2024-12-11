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

int repetitions = 25;
long long dfs(long long curr, int blinks,
              vector<unordered_map<long, long>> &dp) {

  if (blinks == repetitions)
    return 1;

  if (dp[blinks].count(curr) != 0) {
    return dp[blinks][curr];
  }

  if (curr == 0) {
    return dp[blinks][curr] = dfs(curr + 1, blinks + 1, dp);
  } else if (to_string(curr).size() % 2 == 0) {
    string curr_string = to_string(curr);
    int len = curr_string.size() / 2;
    long long left = stoll(curr_string.substr(0, len));
    long long right = stoll(curr_string.substr(len, len));
    return dp[blinks][curr] =
               dfs(left + 1, blinks + 1, dp) + dfs(right + 1, blinks + 1, dp);
  } else {
    return dp[blinks][curr] = dfs((curr * 2024), blinks + 1, dp);
  }
}
int main() {
  string input = read_strings("11_1")[0];
  istringstream iss(input);
  vector<long long> nums;
  while (iss.good()) {
    int temp;
    iss >> temp;
    nums.push_back(temp);
  }

  vector<unordered_map<long, long>> dp(repetitions);

  long long answer = 0;
  vector<long long> temp;
  for (int j = 0; j < nums.size(); j++) {
    long long curr = nums[j];
    dfs(curr, 0, dp);
  }

  for (long long &num : nums) {
    answer += dp[0][num];
  }
  for (int i = 0; i < dp.size(); i++) {
    cout << "LAYER " << i << " -----------------------" << endl;
    for (auto &y : dp[i]) {
      cout << y.first << " " << y.second << endl;
    }
  }
  // print(nums);
  cout << nums.size() << endl;
}
