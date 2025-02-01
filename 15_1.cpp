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
  int id[300][300];
  int tmp[300][300];
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
  int next_id = 1;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (m[r][c] == '@') {
        me = {r, c};
        m[r][c] = '.';
      }
    }
    for (int c = 2 * C - 1; c >= 0; c--) {
      m[r][c] = m[r][c / 2];
      if (m[r][c / 2] == 'O') {
        id[r][c] = next_id;
        if (c % 2 == 0) {
          next_id++;
        }
      }
    }
  }
  C *= 2;
  // for (int r = 0; r < R; r++) {
  //   for (int c = 0; c < C; c++) {
  //     cout << id[r][c] << " ";
  //   }
  //   cout << "\n";
  // }

  me.second *= 2;

  for (char move : moves) {
    pair<int, int> dir = get_direction(move);
    vector<pair<int, int>> boxes;
    set<int> vis;
    boxes.push_back(me);
    bool any_blocked = false;

    for (int i = 0; i < boxes.size(); i++) {
      int row = boxes[i].first + dir.first;
      int col = boxes[i].second + dir.second;
      if (m[row][col] == '#') {
        any_blocked = true;
        break;
      }
      if (m[row][col] == 'O') {
        if (!vis.count(id[row][col])) {
          vis.insert(id[row][col]);
          boxes.emplace_back(row, col);
          for (int c : {col - 1, col + 1}) {
            if (id[row][col] == id[row][c]) {
              boxes.emplace_back(row, c);
            }
          }
        }
      }
    }

    if (!any_blocked) {
      me.first += dir.first;
      me.second += dir.second;
      boxes.erase(boxes.begin());
      for (pair<int, int> box : boxes) {
        m[box.first][box.second] = '.';
        tmp[box.first][box.second] = id[box.first][box.second];
        id[box.first][box.second] = 0;
      }
      for (pair<int, int> box : boxes) {
        id[box.first + dir.first][box.second + dir.second] =
            tmp[box.first][box.second];
        m[box.first + dir.first][box.second + dir.second] = 'O';
      }
    }
  }

  int answer = 0;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (m[r][c] == 'O' && id[r][c] != id[r][c - 1]) {
        answer += 100 * r + c;
      }
    }
  }

  cout << answer << endl;
}
