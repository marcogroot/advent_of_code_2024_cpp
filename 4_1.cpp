#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

string xmas = "XMAS";

void dfs(int r, int c, int letter_index, pair<int, int> dir, int &answer,
         const vector<string> &input, int start_r, int start_c) {

  char curr = input[r][c];
  char letter_to_find = xmas[letter_index];

  if (curr != letter_to_find) {
    return;
  }

  if (curr == 'S') {
    answer++;
    return;
  }

  int new_r = r + dir.first;
  int new_c = c + dir.second;

  if (new_r < 0 || new_c < 0)
    return;
  if (new_r >= input.size() || new_c >= input[0].size())
    return;

  dfs(new_r, new_c, letter_index + 1, dir, answer, input, start_r, start_c);
}
int main() {
  vector<string> input = read_strings("4");
  int row_count = input.size();
  int col_count = input[0].size();
  int answer = 0;

  for (int r = 0; r < row_count; r++) {
    for (int c = 0; c < col_count; c++) {
      char curr = input[r][c];
      if (curr == 'X') {
        for (const auto &dir : directions) {
          dfs(r, c, 0, dir, answer, input, r, c);
        }
      }
    }
  }

  cout << answer << endl;
}
