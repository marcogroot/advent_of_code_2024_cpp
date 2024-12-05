#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<string> input = read_strings("1");
  const int len{static_cast<int>(input.size())};
  vector<int> left(len);
  vector<int> right(len);

  for (int i = 0; i < len; i++) {
    const string &s{input[i]};
    istringstream ss(s);
    int left_num, right_num;
    ss >> left_num >> right_num;
    left[i] = left_num;
    right[i] = right_num;
  }

  unordered_map<int, int> counter;
  for (const int &r : right) {
    counter[r]++;
  }

  int answer = 0;

  for (const int &l : left) {
    answer += (counter[l] * l);
  }

  cout << answer << endl;
}
