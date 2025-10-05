#include <iostream>
#include <sstream>

int main() {
    std::string input = "123 456 -789";

    std::stringstream ss(input);  // wrap the string in a stringstream

    int num;
    while (ss >> num) {
        std::cout << "Read number: " << num << std::endl;
    }

    return 0;
}