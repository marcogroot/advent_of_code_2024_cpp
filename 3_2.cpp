#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mult(const string &s, int i, long long &answer) {
  int start_index = i;
  if (s[i] != 'm')
    return;
  i++;
  if (s[i] != 'u')
    return;
  i++;
  if (s[i] != 'l')
    return;
  i++;
  if (s[i] != '(')
    return;
  i++;

  string temp = "";
  while (isdigit(s[i])) {
    temp += s[i];
    i++;
  }
  if (temp.empty())
    return;
  int num1 = stoi(temp);

  if (s[i] != ',')
    return;
  i++;
  temp = "";
  while (isdigit(s[i])) {
    temp += s[i];
    i++;
  }
  if (temp.empty())
    return;
  int num2 = stoi(temp);

  if (s[i] != ')')
    return;
  answer += (num1 * num2);
  cout << s.substr(start_index, (i - start_index) + 1) << endl;
  return;
}

int main() {
  vector<string> in = read_strings("3");

  long long answer = 0;
  bool do_mul = true;
  for (int j = 0; j < in.size(); j++) {
    string input = in[j];
    int i = 0;
    while (i < input.size()) {
      if (input[i] == 'm' && do_mul) {
        mult(input, i, answer);
      }
      if (input[i] == 'd') {
        if (i < input.size() - 4 && input.substr(i, 4) == "do()") {
          do_mul = true;
        }
        if (i < input.size() - 7 && input.substr(i, 7) == "don't()") {
          do_mul = false;
        }
      }
      i++;
    }
  }

  cout << answer << endl;
}
