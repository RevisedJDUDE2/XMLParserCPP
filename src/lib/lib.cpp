#include <lib.hpp>
#include <iostream>
#include <string>

void Out(void) noexcept {
    fprintf(stderr, "XML is fun??!\n");
};

void XML_PARSER::OpenFile(const std::string& Filename)
{
    std::vector<std::string> Filecontents;
    std::string CurrentLine;
    this->m_Filehandle.open(Filename);
    if(this->m_Filehandle.is_open() == false)
        throw "File does not exist";
    while(std::getline(this->m_Filehandle, CurrentLine))
    {
        Filecontents.push_back(CurrentLine);
    }
    this->m_Filecontents = Filecontents;
}

void XML_PARSER::ScanTags(int Linenumber)
{
    for(char Token : this->m_Filecontents[Linenumber])
    {
        for (int i = 0; i <= sizeof(this->ALOWED_TOKENS); i++)
        {
            if(Token == this->ALOWED_TOKENS[i])
                this->m_Stack_Current_Operator.push_back(Token);
        }
    }
}