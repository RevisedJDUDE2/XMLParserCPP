#include <lib.hpp>
#include <iostream>
#include <string>

void Out(void) noexcept
{
    fprintf(stderr, "XML is fun??!\n");
};

void XML_PARSER::OpenFile(const std::string &Filename)
{
    std::vector<std::string> Filecontents;
    std::string CurrentLine;
    this->m_Filehandle.open(Filename);
    if (this->m_Filehandle.is_open() == false)
        throw "File does not exist";
    while (std::getline(this->m_Filehandle, CurrentLine))
    {
        Filecontents.push_back(CurrentLine);
    }
    this->m_Filecontents = Filecontents;
}
void XML_PARSER::ScanTags(int Linenumber)
{
    bool isOpened;
    std::string ElmntName;
    int index = 0;
    this->Element_Names.push_back(ElmntName);
    for (char Token : this->m_Filecontents[Linenumber])
    {
        index += 1;
        //TODO: fix this:
        for (int i = 0; i <= sizeof(this->ALOWED_TOKENS); i++)
        {
            if (Token == this->ALOWED_TOKENS[i])
            {
                this->m_Stack_Current_Operator.push_back(Token);
                isOpened = true;
            }
        }
        if(Token != ' ' && isOpened)
        {
            if(this->m_Filecontents[Linenumber][index + 1] != '>')
            {
                ElmntName.push_back(Token);
            }
            else
            {
                throw "Closing tag required: '>';";
                break;
            }
        }
    }
}
bool XML_PARSER::m_HasFoundClosingTag(int Linenumber)
{
    if (this->m_Stack_Current_Operator[0] == this->TAG_STRUCT[0])
    {
        if (this->m_Filecontents[Linenumber][this->m_Filecontents[Linenumber].size() - 1] == this->TAG_STRUCT[5])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        throw "There is no opening tag \"<\"";
    }
}