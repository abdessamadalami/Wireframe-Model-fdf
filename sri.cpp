#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main() {
    std::ifstream file("my.txt"); // Replace with the actual file name
    std::string line;
    int a = 0;
    while (std::getline(file, line)) {
        std::cout << line;
        std::string command = line;
          std::cout << command;
        int result = system(command.c_str());
        a++;
        result = system("git push");
    }

    file.close();

    return 0;
}