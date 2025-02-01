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

pair<int, int> get_direction(char c) {
  if (c == '^')
    return {-1, 0};
  if (c == 'v')
    return {1, 0};
  if (c == '>')
    return {0, 1};
  if (c == '<')
    return {0, -1};

  cout << "Unexpected dir" << endl;
  return {-999999, -999999};
}

int main() {
  vector<string> input = read_strings("15");
  vector<string> m(50);
  for (int i = 0; i < 50; i++) {
    m[i] = input[i];
  }

  string moves = "";
  for (int i = 51; i < input.size(); i++) {
    moves += input[i];
  }

  int R = m.size();
  int C = m[0].size();

  pair<int, int> me{-1, -1};
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (m[r][c] == '@') {
        me = {r, c};
        m[r][c] = '.';
      }
    }
  }

  for (char move : moves) {
    pair<int, int> dir = get_direction(move);
    vector<pair<int, int>> boxes;
    int row = me.first;
    int col = me.second;
    bool empty_space = false;
    while (true) {
      row += dir.first;
      col += dir.second;
      if (m[row][col] == '#') {
        break;
      }
      if (m[row][col] == '.') {
        empty_space = true;
        break;
      }
      boxes.emplace_back(row, col);
    }
    if (empty_space) {
      me.first += dir.first;
      me.second += dir.second;
      for (pair<int, int> box : boxes) {
        m[box.first][box.second] = '.';
      }
      for (pair<int, int> box : boxes) {
        m[box.first + dir.first][box.second + dir.second] = 'O';
      }
    }
  }

  int answer = 0;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (m[r][c] == 'O') {
        answer += 100 * r + c;
      }
    }
  }

  cout << answer << endl;
}
