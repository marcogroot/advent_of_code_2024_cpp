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

pair<int, int> get_xy(const string &input) {
  vector<int> symb_indexes;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'X' || input[i] == 'Y') {
      symb_indexes.push_back(i + 2);
    }
    if (input[i] == ',') {
      symb_indexes.push_back(i);
    }
  }
  int x = stoi(input.substr(symb_indexes[0], symb_indexes[1] - symb_indexes[0]));
  int y = stoi(input.substr(symb_indexes[2]));
  return make_pair(x, y);
}

long long calculate(pair<int, int> &a, pair<int, int> &b, pair<long long, long long> &p) {
  long long t = ((b.second * a.first) - (b.first * a.second));
  long long t2 = ((p.second * a.first) - (p.first * a.second));
  long long b_pressed = t2 / t;

  long long k = (a.second * b.first - a.first * b.second);
  long long k2 = (p.second * b.first - p.first * b.second);
  long long a_pressed = k2 / k;

  if ((a_pressed * a.first + b_pressed * b.first == p.first) && (a_pressed * a.second + b_pressed * b.second == p.second)) {
    cout << "pressed a " << a_pressed << " and b " << b_pressed << endl;
    return (3 * a_pressed) + (b_pressed);
  } else
    return 0;
}

int main() {
  long long answer = 0;
  vector<string> input = read_strings("13");

  cout << input.size() << endl;

  for (int i = 0; i < input.size(); i += 4) {
    pair<int, int> a = get_xy(input[i]);
    pair<int, int> b = get_xy(input[i + 1]);
    pair<long long, long long> prize = get_xy(input[i + 2]);
    prize.first += 10000000000000;
    prize.second += 10000000000000;

    answer += calculate(a, b, prize);
  }

  cout << answer << endl;
}
