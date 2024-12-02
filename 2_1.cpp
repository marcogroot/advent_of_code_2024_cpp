#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  vector<string> input = read_strings("2");
  int len = input.size();

  int answer = 0;
  for (int i = 0; i < len; i++) {
    const string &s{input[i]};
    vector<int> report;
    istringstream ss(s);
    int temp;
    while (ss) {
      ss >> temp;
      report.push_back(temp);
    }
    report.pop_back();

    bool flag_1 = true;
    bool flag_2 = true;

    if (report.size() <= 1) {
      answer++;
      continue;
    }

    bool increasing = report[1] > report[0];

    if (increasing) {
      for (int i = 1; i < report.size(); i++) {
        if (report[i] < report[i - 1])
          flag_1 = false;
      }
    } else {
      for (int i = 1; i < report.size(); i++) {
        if (report[i] > report[i - 1])
          flag_1 = false;
      }
    }

    for (int i = 1; i < report.size(); i++) {
      int diff = abs(report[i] - report[i - 1]);
      if (diff > 3 || diff < 1)
        flag_2 = false;
    }

    if (flag_1 && flag_2)
      answer++;
  }

  cout << answer << endl;
}
