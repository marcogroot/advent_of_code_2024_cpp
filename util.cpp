#include <iostream>
#include <fstream>
#include <vector>
#include <util.h>

std::vector<std::string> read_strings(std::string file_name) {
    std::string text;
    std::ifstream file_read("files/"+file_name+".txt");
    std::vector<std::string> f;

    while (getline (file_read, text)) {
        f.emplace_back(text);
    }

    if (f.empty()) std::cout << "Empty input" << std::endl;
    file_read.close();
    return f;
}

std::vector<int> read_ints(std::string file_name) {
    std::string text;
    std::ifstream file_read("files/"+file_name+".txt");
    std::vector<int> f;

    while (getline (file_read, text)) {
        f.emplace_back(stoi(text));
    }

    if (f.empty()) std::cout << "Empty input" << std::endl;
    file_read.close();
    return f;
}
