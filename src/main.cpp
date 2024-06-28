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
        XML_PARSER::LINE_STRUCT_T name;
        parser.OpenFile(filename);
        parser.ScanTags(2);
        parser.GetElementAtLine(&name, 0);
        std::cout << "Current Operator: " << parser.GetStackCurrentOperator()[0] << std::endl;
        parser.ClearStack();
        std::cout << "Element Names Captured: " << parser.GetElementNames()[1] << std::endl;
        std::cout << "name->tagname = \"" << name.OpeningTag << "\"\n";
    } catch (const char* errout)
    {
        std::cout << errout << std::endl;
    }
    return 0;
}