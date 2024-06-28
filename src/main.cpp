#include <iostream>
#include <fstream>
#include <lib/lib.hpp>
#include <optional>

typedef void(*Outp)(void)noexcept;

int main()
{
    try
    {
        Outp();
        std::string filename = "sample.xml";
        XML_PARSER parser;
        parser.OpenFile(filename);
        parser.ScanTags(2);
        std::cout << "Current Operator: " << parser.GetStackCurrentOperator()[0] << std::endl;
        std::cout << "Element Names Captured: " << parser.GetElementNames()[1] << std::endl;
    } catch (const char* errout)
    {
        std::cout << errout << std::endl;
    }
    return 0;
}