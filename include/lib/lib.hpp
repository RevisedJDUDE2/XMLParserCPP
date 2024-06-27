#ifndef LIB_HPP
#define LIB_HPP
typedef struct XMLProlog {
    bool found_first_tag;

    bool found_last_tag;
} XMLProlog_t;

#ifdef __cplusplus
#include <vector>
#include <string>
#include <cstdio>
#include <optional>
#include <fstream>

std::optional<XMLProlog_t> xml_init(std::ifstream* data);

#else
#include <stdio.h>
XMLProlog_t* xml_init(const char* data);
#endif

//void Out(void) noexcept;
#endif