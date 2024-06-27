#include <lib.hpp>
#include <iostream>
#include <string>

void Out(void) noexcept {
    fprintf(stderr, "XML is fun??!\n");
};

XMLProlog_t* xml_init(const char* data) {
    return NULL;
}

XMLProlog_t* xml_init(std::ifstream* data) {
    std::vector<std::string> lines;
    std::string Current_Line;
    while(std::getline(*data, Current_Line)) {
        std::cout << Current_Line << std::endl;
        lines.push_back(Current_Line);
    }
    XMLProlog_t* prlog;
    bool first_identifier = (lines[0][0] == '<') ? (lines[0][1] == '?') ? true : false : false;
    prlog->found_first_tag = first_identifier;
    bool second_identifier = (lines[0].size() == '>') ? (lines[0].size()-1 == '?') ? true : false : false;
    prlog->found_last_tag = second_identifier;
    return prlog;
}