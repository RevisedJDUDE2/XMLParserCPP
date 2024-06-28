#include <iostream>
#include <fstream>
#include <lib/lib.hpp>
#include <optional>

int main()
{
    try
    {
        std::string filename = "sample.xml";
        XML_PARSER parser;
        parser.OpenFile(filename);
        parser.ScanTags(1);
        std::cout << "Current Operator: " << parser.GetStackCurrentOperator()[0] << std::endl;
    } catch (const char* errout)
    {
        std::cout << errout << std::endl;
    }
    return 0;
}