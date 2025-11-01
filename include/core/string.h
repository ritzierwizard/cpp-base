#pragma once

#include "type_aliases.h"
#include <cstdlib>

struct StringBuilder;
struct String;

struct StringBuilder
{
    char *data;
    usize length;
    usize cap;

    void append(char ch)
    {
        if (length >= cap)
        {
            cap *= 2;
            data = (char *)realloc(data, cap);
        }

        data[length] = ch;
        length++;
    }

    StringBuilder(usize capacity)
    {
        data = (char *)malloc(sizeof(char) * capacity);
        cap = capacity;
        length = 0;
    }
};

struct String
{
    const char *data;
    usize length;

    String(StringBuilder *sb)
    {
        data = sb->data;
        length = sb->length;
    }
};
