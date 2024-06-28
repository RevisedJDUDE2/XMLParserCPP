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
        if(Token != ' ')
        {
            index += 1;
        }
        if(Token == '<' && isOpened == false)
        {
            //this->m_Stack_Current_Operator.push_back(Token);
            ElmntName.push_back(Token);
            isOpened = true;
        }
        if(Token != ' ' && isOpened)
        {
            ElmntName.push_back(Token);
            if(Token == '>') {
                this->Element_Names.push_back(ElmntName);
                break;
            }
        }
    }
}