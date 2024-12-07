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

bool dfs(long long total, int index, int op, long long goal,
         vector<long long> &nums) {
  long long curr = nums[index];
  if (op == 0) {
    total += curr;
  } else if (op == 1) {
    total *= curr;
  } else {
    string string_a = to_string(total);
    string string_b = to_string(curr);
    string new_total = string_a + string_b;
    total = stoll(new_total);
  }

  if (index == nums.size() - 1) {
    return total == goal;
  }

  return dfs(total, index + 1, 0, goal, nums) ||
         dfs(total, index + 1, 1, goal, nums) ||
         dfs(total, index + 1, 2, goal, nums);
}
int main() {
  long long answer = 0;
  vector<string> input = read_strings("7");

  for (string &s : input) {
    int i = 0;
    int colon_index = 0;
    while (i < s.size()) {
      if (s[i] == ':') {
        colon_index = i;
        i = s.size();
      }
      i++;
    }

    long long goal = stol(s.substr(0, colon_index));
    string rest = s.substr(colon_index + 1);
    stringstream ss(rest);
    vector<long long> nums;
    string tempstr;
    while (ss >> tempstr) {
      long long n = stoll(tempstr);
      nums.push_back(n);
    }

    bool good = dfs(nums[0], 1, 0, goal, nums) ||
                dfs(nums[0], 1, 1, goal, nums) ||
                dfs(nums[0], 1, 2, goal, nums);
    if (good) {
      answer += goal;
    }
  }

  cout << answer << endl;
}
