#include "util.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mult(const string &s, int i, long long &answer) {
  int start_index = i;
  // cout << "starting i " << i << endl;
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

  // cout << i << " reached here " << endl;
  string temp = "";
  while (isdigit(s[i])) {
    temp += s[i];
    i++;
  }
  if (temp.empty())
    return;
  int num1 = stoi(temp);

  // cout << "num 1 is " << num1 << endl;
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

  // cout << "num 2 is " << num2 << endl;
  if (s[i] != ')')
    return;
  // cout << num1 * num2 << endl;
  answer += (num1 * num2);
  cout << s.substr(start_index, (i - start_index) + 1) << endl;
  return;
}

int main() {
  vector<string> in = read_strings("3");

  long long answer = 0;
  for (int j = 0; j < in.size(); j++) {
    string input = in[j];
    int i = 0;
    while (i < input.size()) {
      if (input[i] == 'm') {
        mult(input, i, answer);
      }
      i++;
    }
  }

  cout << answer << endl;
}
