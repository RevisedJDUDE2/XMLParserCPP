#ifndef LIB_HPP
#define LIB_HPP

#ifdef __cplusplus
#include <vector>
#include <string>
#include <cstdio>
#include <optional>
#include <fstream>
#include <regex>
#include <cstring>

class XML_PARSER
{
private:
   std::vector<char> m_Stack_Current_Operator;
   std::vector<std::string> Element_Names;
   std::vector<std::string> m_Filecontents;
   std::ifstream m_Filehandle;
   int m_Linenumber;
public:
    typedef struct LINE_STRUCTURE {
        std::string OpeningTag, Value, ClosingTag;
        std::string Attribute, Element;
        int LineNumber, StrLastPos, RawStrLastPos; //SO, WHERE IN THE FILE AND WHAT IS THE LAST POS OF INDEX
    } LINE_STRUCT_T;
    void OpenFile(const std::string& Filename);
    void ScanTags(XML_PARSER::LINE_STRUCT_T* table, int Linenumber);
    inline std::vector<std::string> GetFileContents(void) const noexcept { return this->m_Filecontents; };
    inline std::vector<char> GetStackCurrentOperator(void) const noexcept { return this->m_Stack_Current_Operator; };
    inline std::vector<std::string> GetElementNames(void) const noexcept { return this->Element_Names; };
    void GetElementAtLine(XML_PARSER::LINE_STRUCT_T* table, int pos);
    void GetElementAtLine(XML_PARSER::LINE_STRUCT_T* table);
    void ClearStack(void) noexcept { this->m_Stack_Current_Operator.clear(); };
    void CheckValueAndClosingTag(XML_PARSER::LINE_STRUCT_T* table);
    void CheckValueAndClosingTag__EXPERIMENTAL(XML_PARSER::LINE_STRUCT_T* table);
};

#else
#include <stdio.h>
// C IMPLEMENTATION SOON
#endif
#endif