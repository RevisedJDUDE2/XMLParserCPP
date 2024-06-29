#include <lib.hpp>
#include <iostream>
#include <string>
#include <iterator>

void Out(void) noexcept
{
    fprintf(stderr, "XML is fun\n");
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
void XML_PARSER::ScanTags(XML_PARSER::LINE_STRUCT_T *table, int Linenumber)
{
    bool isOpened;
    std::string ElmntName;
    int index = 0;
    this->Element_Names.push_back(ElmntName);
    for (char Token : this->m_Filecontents[Linenumber])
    {
        if (Token != ' ')
        {
            table->RawStrLastPos += 1;
            index += 1;
        }
        if (Token == '<' && isOpened == false)
        {
            this->m_Stack_Current_Operator.push_back(Token);
            isOpened = true;
        }
        if (Token != ' ' && isOpened)
        {
            ElmntName.push_back(Token);
            if (Token == '<' || Token == '>')
            {
                ElmntName.pop_back();
                index -= 1;
            }
            if (Token == '>')
            {
                this->Element_Names.push_back(ElmntName);
                // DEP: this->m_Linenumber = Linenumber;
                table->LineNumber = Linenumber;
                table->StrLastPos = index;
                break;
            }
        }
    }
    // this->CheckValueAndClosingTag(table);
    this->CheckValueAndClosingTag__EXPERIMENTAL(table);
}
void XML_PARSER::CheckValueAndClosingTag(XML_PARSER::LINE_STRUCT_T *table)
{
    std::string value_buffer;
    std::vector<std::string>::iterator itstring;
    std::size_t optr;
    for (int i = table->RawStrLastPos; i <= this->m_Filecontents[table->LineNumber].size() - 1; i++)
    {
        if (this->m_Filecontents[table->LineNumber][i] != '>')
        {
            if (this->m_Filecontents[table->LineNumber][i] != '<')
            {
                value_buffer.push_back(this->m_Filecontents[table->LineNumber][i]);
            }
            else if (this->m_Filecontents[table->LineNumber][i] == '<')
            {
                table->Value = value_buffer;
                table->RawStrLastPos = i;
                break;
            }
        }
    };
}
void XML_PARSER::GetElementAtLine(XML_PARSER::LINE_STRUCT_T *table)
{
    table->OpeningTag = this->Element_Names.back().c_str();
}
void XML_PARSER::GetElementAtLine(XML_PARSER::LINE_STRUCT_T *table, int pos)
{
    table->OpeningTag = this->Element_Names[pos].c_str();
}
void XML_PARSER::CheckValueAndClosingTag__EXPERIMENTAL(XML_PARSER::LINE_STRUCT_T *table)
{
    std::string value_buffer;
    std::string closing_tag_buffer;
    bool is_reading_value = false;
    bool is_reading_closing_tag = false;

    for (std::size_t i = table->RawStrLastPos; i < this->m_Filecontents[table->LineNumber].size(); ++i)
    {
        char current_char = this->m_Filecontents[table->LineNumber][i];

        if (!is_reading_value)
        {
            if (current_char == '>') // Start reading value after '>'
            {
                is_reading_value = true;
                continue;
            }
        }
        else
        {
            if (current_char == '<') // Start reading closing tag
            {
                is_reading_closing_tag = true;
                continue;
            }
            if (is_reading_closing_tag)
            {
                if (current_char == '/') // Skip '/' character in closing tag
                {
                    continue;
                }
                if (current_char == '>') // End of closing tag found
                {
                    table->ClosingTag = closing_tag_buffer;
                    table->Value = value_buffer;
                    table->RawStrLastPos = i + 1; // Move past the '>'
                    return;
                }
                closing_tag_buffer.push_back(current_char);
            }
            else
            {
                value_buffer.push_back(current_char);
            }
        }
    }
}