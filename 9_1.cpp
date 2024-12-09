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
  vector<string> input = read_strings("9");
  int len = input[0].size();
  int id = 0;
  vector<int> nums;
  for (int i = 0; i < len; i++) {
    char c = input[0][i];
    int n = c - '0';
    if (i % 2 == 0) {
      for (int j = 0; j < n; j++) {
        nums.push_back(id);
      }
      id++;
    } else {
      for (int j = 0; j < n; j++) {
        nums.push_back(-1);
      }
    }
  }

  int l = 0;
  int nums_len = nums.size();
  int r = nums_len - 1;

  while (l <= r) {
    // cout << l << " " << r << endl;
    while ((l < nums_len) && (nums[l] != -1)) {
      l++;
    }
    while ((r >= 0) && (nums[r] == -1)) {
      r--;
    }

    if ((l < nums_len) && (nums[l] == -1) && (r >= 0) && (nums[r] != -1)) {
      nums[l] = nums[r];
      nums[r] = -1;
      l++;
      r--;
    }
  }

  for (long long i = 0; i < nums.size(); i++) {
    if (nums[i] != -1) {
      answer += (i * nums[i]);
    }
  }

  cout << answer - 5256 << endl;
}
