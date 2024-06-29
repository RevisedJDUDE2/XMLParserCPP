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
        XML_PARSER::LINE_STRUCT_T Element_Structure;
        parser.OpenFile(filename);
        parser.ScanTags(&Element_Structure, 2);
        //parser.GetElementAtLine(&name, 0);
        std::cout << "Current Operator: " << parser.GetStackCurrentOperator()[0] << std::endl;
        parser.ClearStack();
        std::cout << "Element Names Captured: " << parser.GetElementNames()[1] << std::endl;
        parser.GetElementAtLine(&Element_Structure, 1);
        std::cout << "name->tagname = \"" << Element_Structure.OpeningTag << "\"\n";
        std::cout << Element_Structure.StrLastPos << std::endl;
    } catch (const char* errout)
    {
        std::cout << errout << std::endl;
    }
    return 0;
}