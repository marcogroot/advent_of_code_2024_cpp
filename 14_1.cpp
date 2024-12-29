#include "util.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<int> get_xy(const string &input) {
  vector<int> symb_indexes;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '=' || input[i] == ' ' || input[i] == ',') {
      symb_indexes.push_back(i);
    }
  }
  int p1 = stoi(input.substr(symb_indexes[0] + 1, symb_indexes[1] - symb_indexes[0] - 1));
  int p2 = stoi(input.substr(symb_indexes[1] + 1, symb_indexes[2] - symb_indexes[1] - 1));
  int p3 = stoi(input.substr(symb_indexes[3] + 1, symb_indexes[4] - symb_indexes[3] - 1));
  int p4 = stoi(input.substr(symb_indexes[4] + 1));
  return {p1, p2, p3, p4};
}

int main() {
  vector<vector<long long>> ans(2, vector<long long>(2));
  vector<string> input = read_strings("14");
  const int W = 101;
  const int H = 103;

  for (int i = 0; i < input.size(); i++) {
    vector<int> nums = get_xy(input[i]);
    nums[0] = ((nums[0] + nums[2] * 100) % W + W) % W;
    nums[1] = ((nums[1] + nums[3] * 100) % H + H) % H;
    if (nums[0] != W / 2 && nums[1] != H / 2) {
      ans[nums[0] > W / 2][nums[1] > H / 2]++;
    }
  }

  long long answer = ans[0][0] * ans[0][1] * ans[1][0] * ans[1][1];

  cout << answer << endl;
}
