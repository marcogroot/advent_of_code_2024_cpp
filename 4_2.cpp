#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

string xmas = "MAS";

bool is_valid(int r, int c, const vector<string> &input) {
  if (r < 0 || c < 0)
    return false;
  if (r >= input.size() || c >= input[0].size())
    return false;
  return true;
}
void dfs(int r, int c, int letter_index, pair<int, int> dir, int &answer,
         const vector<string> &input, int start_r, int start_c) {

  char curr = input[r][c];
  char letter_to_find = xmas[letter_index];

  if (curr != letter_to_find) {
    return;
  }

  if (curr == 'S') {
    int r1 = r;
    int c1 = start_c;

    int r2 = start_r;
    int c2 = c;

    if (is_valid(r1, c1, input) && is_valid(r2, c2, input)) {
      char char_1 = input[r1][c1];
      char char_2 = input[r2][c2];

      bool has_s = char_1 == 'S' || char_2 == 'S';
      bool has_m = char_1 == 'M' || char_2 == 'M';

      if (has_m && has_s) {
        // cout << start_r << " " << start_c << " - " << r << " " << c << endl;
        answer++;
      }
    }

    return;
  }

  int new_r = r + dir.first;
  int new_c = c + dir.second;

  if (is_valid(new_r, new_c, input)) {
    dfs(new_r, new_c, letter_index + 1, dir, answer, input, start_r, start_c);
  }
}
int main() {
  vector<string> input = read_strings("4");
  int row_count = input.size();
  int col_count = input[0].size();
  int answer = 0;

  for (int r = 0; r < row_count; r++) {
    for (int c = 0; c < col_count; c++) {
      char curr = input[r][c];
      if (curr == 'M') {
        for (const auto &dir : directions) {
          dfs(r, c, 0, dir, answer, input, r, c);
        }
      }
    }
  }

  cout << answer / 2 << endl;
}
