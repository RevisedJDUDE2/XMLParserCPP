#include <iostream>
#include <fstream>
#include <lib/lib.hpp>

int main() {
    std::fprintf(stderr, "Hello World?\n");
    std::ifstream file("sample.xml");
    XMLProlog_t* sample = xml_init(&file);
    if(sample != NULL) {
        std::cout << "is NOT null" << std::endl;
    } else {
        std::cout << "is null" << std::endl;
    }
    if(sample->found_first_tag) {
        std::cout << "Found <?" << std::endl;
    } else {
        std::cout << "Syntax Error Expected <?" << std::endl;
    }
    if(sample->found_last_tag) {
        std::cout << "Found ?>" << std::endl;
    } else {
        std::cout << "Syntax Error Expected ?>" << std::endl;
    }
    return 0;
}