#include <iostream>
#include <fstream>
#include <lib/lib.hpp>
#include <optional>

int main() {
    std::string filename = "sample.xml";
    XML_PARSER parser;
    parser.OpenFile(filename);
    parser.ScanTags(1);
    std::cout << "Current Operator: " << parser.GetStackCurrentOperator()[0] << std::endl;
    return 0;
}