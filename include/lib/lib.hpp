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
    typedef struct LINE_STRUCTURE {
        std::string OpeningTag, Value, ClosingTag;
        std::string Attribute, Element;

   } LINE_STRUCT_T;
   std::vector<char> m_Stack_Current_Operator;
   std::vector<std::string> Element_Names;
   std::vector<std::string> m_Filecontents;
   std::ifstream m_Filehandle;
public:
    void OpenFile(const std::string& Filename);
    void ScanTags(int Linenumber);
    inline std::vector<std::string> GetFileContents(void) const noexcept { return this->m_Filecontents; };
    inline std::vector<char> GetStackCurrentOperator(void) const noexcept { return this->m_Stack_Current_Operator; };
    inline std::vector<std::string> GetElementNames(void) const noexcept { return this->Element_Names; };
};

#else
#include <stdio.h>
// C IMPLEMENTATION SOON
#endif
#endif