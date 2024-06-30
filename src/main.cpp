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
        parser.ClearStack();
        XML_PARSER::LINE_STRUCT_T main__xml;
        parser.ScanTags(&main__xml, 1);
        parser.GetElementAtLine(&main__xml, 1);
        std::cout << "First Tag (Not Including the prolog): " << main__xml.OpeningTag << std::endl;
        parser.ClearStack();
        XML_PARSER::LINE_STRUCT_T Element_Structure;
        parser.ScanTags(&Element_Structure, 2);
        parser.GetElementAtLine(&Element_Structure /*, 2*/);
        parser.CheckValueAndClosingTag__EXPERIMENTAL(&Element_Structure);
        std::cout << "name->tagname = \"" << Element_Structure.OpeningTag << "\"\n";
        std::cout << Element_Structure.Value << std::endl;
        std::cout << Element_Structure.StrLastPos << std::endl;
        parser.ClearStack();
        XML_PARSER::LINE_STRUCT_T AgeElement;
        parser.ScanTags(&AgeElement, 3);
        parser.GetElementAtLine(&AgeElement);
        std::cout << AgeElement.OpeningTag << std::endl;
        std::cout << AgeElement.Value << std::endl;
    } catch (const char* errout)
    {
        std::cout << errout << std::endl;
    }
    return 0;
}