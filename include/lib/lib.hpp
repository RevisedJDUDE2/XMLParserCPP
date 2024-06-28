#ifndef LIB_HPP
#define LIB_HPP

#ifdef __cplusplus
#include <vector>
#include <string>
#include <cstdio>
#include <optional>
#include <fstream>
#include <regex>

class XML_PARSER
{
private:
    const char* ALOWED_TOKENS = "<?>=\"\"\'\'/\\";
    typedef struct LINE_STRUCTURE {
        std::string OpeningTag, Value, ClosingTag;
        std::string Attribute, Element;

   } LINE_STRUCT_T;
   std::vector<char> m_Stack_Current_Operator;
   std::vector<std::string> m_Filecontents;
   std::ifstream m_Filehandle;
public:
    void OpenFile(const std::string& Filename);
    void ScanTags(int Linenumber);
    inline std::vector<std::string> GetFileContents(void) const noexcept { return this->m_Filecontents; };
    inline std::vector<char> GetStackCurrentOperator(void) const noexcept { return this->m_Stack_Current_Operator; };
};

#else
#include <stdio.h>
XMLProlog_t* xml_init(const char* data);
#endif

//void Out(void) noexcept;
#endif