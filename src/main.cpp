#include <iostream>
#include <fstream>
#include <lib/lib.hpp>
#include <optional>

int main() {
    std::fprintf(stderr, "Hello World?\n");
    std::ifstream file("sample.xml");
    // OLD: XMLProlog_t* sample = xml_init(&file);
    std::optional<XMLProlog_t> sample = xml_init(&file);
    std::cout << sample->version << std::endl;
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