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
  vector<pair<int, int>> free_blocks;
  vector<pair<int, int>> used_blocks;
  for (int i = 0; i < len; i++) {
    char c = input[0][i];
    int n = c - '0';
    if (i == 0 || i % 2 == 0) {
      used_blocks.push_back({nums.size(), n});
      for (int j = 0; j < n; j++) {
        nums.push_back(id);
      }
      id++;
    } else {
      free_blocks.push_back({nums.size(), n});
      for (int j = 0; j < n; j++) {
        nums.push_back(-1);
      }
    }
  }

  int l = 0;
  int nums_len = nums.size();
  int r = nums_len - 1;

  for (int i = used_blocks.size() - 1; i >= 0; i--) {
    pair<int, int> curr = used_blocks[i];
    int used_s = curr.first;
    int used_l = curr.second;

    for (int free_index = 0; free_index < free_blocks.size(); free_index++) {
      pair<int, int> free_block = free_blocks[free_index];
      int free_s = free_block.first;
      int free_l = free_block.second;

      if (free_s + free_l > used_s) {
        break;
      }

      if (free_l >= used_l) {
        for (int j = free_s; j < free_s + used_l; j++) {
          nums[j] = nums[used_s];
        }
        for (int j = used_s; j < used_s + used_l; j++) {
          nums[j] = -1;
        }

        free_blocks = {};
        int x = 0;
        while (x < nums.size()) {
          if (nums[x] == -1) {
            int start = x;
            int count = 0;
            while ((x < nums.size()) && (nums[x] == -1)) {
              count++;
              x++;
            }
            free_blocks.push_back({start, count});
          } else {
            x++;
          }
        }
        break;
      }
    }
  }

  for (long long i = 0; i < nums.size(); i++) {
    if (nums[i] != -1) {
      answer += (i * nums[i]);
    }
  }

  cout << answer << endl;
}
