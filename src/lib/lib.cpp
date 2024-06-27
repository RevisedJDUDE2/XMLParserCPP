#include <lib.hpp>
#include <iostream>
#include <string>

void Out(void) noexcept {
    fprintf(stderr, "XML is fun??!\n");
};

XMLProlog_t* xml_init(const char* data) {
    return NULL;
}

std::optional<XMLProlog_t> xml_init(std::ifstream* data) {
    std::vector<std::string> lines;
    std::string Current_Line;
    while(std::getline(*data, Current_Line)) {
        std::cout << Current_Line << std::endl;
        lines.push_back(Current_Line);
    }
    if(lines.empty()) {
        std::nullopt;
    }
    XMLProlog_t prlog;
    // OLD: bool first_identifier = (lines[0][0] == '<') ? (lines[0][1] == '?') ? true : false : false;
    bool first_identifier = (lines[0].size() > 1 && lines[0][0] == '<' && lines[0][1] == '?') ? true : false;
    prlog.found_first_tag = first_identifier;
    // OLD: bool second_identifier = (lines[0].size() == '>') ? (lines[0].size()-1 == '?') ? true : false : false;
    bool second_identifier = (lines[0].size() > 2 && lines[0][lines[0].size() - 2] == '?' && lines[0][lines[0].size() - 1] == '>') ? true : false;
    prlog.found_last_tag = second_identifier;

    // OLD: std::regex version_regex("(version)\=\"");
    // OLD: std::regex version_regex(R"(version\"\=())");
    std::regex version_regex("(version)\\=\"\\d*\\.\\d*\"");
    std::smatch matches;
    if(std::regex_match(lines[0], matches, version_regex)) {
        std::cout << "Found Version Regex" << std::endl;
        //get the postion in the string starting from the regex ((version)\=\") so starting from 1.0 from version="";
        if(matches.size() > 1) {
            std::string ver = matches[1].str();
            std::cout << ver << std::endl;
            prlog.version = (char*)ver.c_str();
        }
        prlog.version = (char*)"NULL";
    }

    return prlog;
}