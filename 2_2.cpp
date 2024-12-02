#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool check(vector<int> report, int ignore) {
  report.erase(report.begin() + ignore);
  if (report.size() <= 1)
    return true;

  bool increasing = report[1] > report[0];
  for (int i = 0; i < report.size(); i++) {
    if (increasing) {
      for (int i = 1; i < report.size(); i++) {
        if (report[i] < report[i - 1]) {
          return false;
        }
      }
    } else {
      for (int i = 1; i < report.size(); i++) {
        if (report[i] > report[i - 1])
          return false;
      }
    }

    for (int i = 1; i < report.size(); i++) {
      int diff = abs(report[i] - report[i - 1]);
      if (diff > 3 || diff < 1)
        return false;
    }
  }
  return true;
}

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

    if (report.size() <= 1) {
      answer++;
      continue;
    }

    bool works = false;

    for (int i = 0; i < report.size(); i++) {
      works = works || check(report, i);
    }

    if (works)
      answer++;
  }

  cout << answer << endl;
}
