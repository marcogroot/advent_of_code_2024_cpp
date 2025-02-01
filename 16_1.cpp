#include "util.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

struct State {
  int r, c, d;
  bool operator<(const State &he) const {
    return make_pair(r, make_pair(c, d)) <
           make_pair(he.r, make_pair(he.c, he.d));
  }
};

int main() {
  pair<int, int> start, target;
  vector<string> input = read_strings("16");
  int R = input.size();
  int C = input[0].size();

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (input[r][c] == 'S') {
        start = {r, c};
        input[r][c] = '.';
      }
      if (input[r][c] == 'E') {
        target = {r, c};
        input[r][c] = '.';
      }
    }
  }

  set<pair<int, State>> s;
  map<State, int> dist;
  State starting_state{start.first, start.second, 0};
  dist[starting_state] = 0;
  s.insert(make_pair(0, starting_state));
  while (!s.empty()) {
    State state = s.begin()->second;
    s.erase(s.begin());
    for (int i = 0; i < 3; i++) {
      int maybe = dist[state];
      State s2 = state;
      if (i == 0) {
        s2.r += dirs[s2.d].first;
        s2.c += dirs[s2.d].second;
        if (!(0 <= s2.r && s2.r < R && 0 <= s2.c && s2.c <= C)) {
          continue;
        }
        if (input[s2.r][s2.c] == '#') {
          continue;
        }
        maybe++;
      } else if (i == 1) {
        s2.d = (s2.d + 1) % 4;
        maybe += 1000;
      } else {
        s2.d = (s2.d + 3) % 4;
        maybe += 1000;
      }
      if (!dist.count(s2) || dist[s2] > maybe) {
        if (dist.count(s2)) {
          s.erase(make_pair(dist[s2], s2));
        }
        dist[s2] = maybe;
        s.insert(make_pair(maybe, s2));
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < 4; i++) {
    State t{target.first, target.second, i};
    if (dist.count(t)) {
      ans = min(ans, dist[t]);
    }
  }
  cout << ans << endl;
}
