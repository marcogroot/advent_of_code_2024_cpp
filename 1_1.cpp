#include <iostream>
#include "util.h"
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    vector<string> input = read_strings("1");
    const int len { static_cast<int>(input.size()) };
    vector<int> left(len);
    vector<int> right(len);

    for (int i = 0 ; i < len; i++) {
        const string& s { input[i]};
        istringstream ss(s);
        int left_num, right_num;
        ss >> left_num >> right_num;
        left[i] = left_num;
        right[i] = right_num;
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int answer = 0;

    for (int i = 0 ; i < len; i++) {
        answer += abs(left[i]-right[i]);
    }

    cout << answer << endl;
}
