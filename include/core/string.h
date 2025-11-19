#ifndef BASE_STRING_H
#define BASE_STRING_H

#include <cstdlib>

struct StringBuilder {
	char* data;
	size_t length;
	size_t cap;

	void append(const char ch) {
		if (length >= cap) {
			cap *= 2;
			data = static_cast<char*>(realloc(data, cap));
		}

		data[length] = ch;
		length++;
	}

	explicit StringBuilder(const size_t capacity) {
		data = static_cast<char*>(malloc(sizeof(char) * capacity));
		cap = capacity;
		length = 0;
	}
};

struct String {
	const char* data;
	size_t length;

	explicit String(const struct StringBuilder* sb) {
		data = sb->data;
		length = sb->length;
	}
};

#endif // BASE_STRING_H
