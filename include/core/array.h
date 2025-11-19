//
// Created by joshua on 11/19/25.
//

#ifndef BASE_ARRAY_H
#define BASE_ARRAY_H
#include <stdlib.h>

template <typename T>
struct Array {
	T* data;
	size_t count;

	Array(const T* src, const size_t size) {
		data = static_cast<T*>(__builtin_memcpy(this->data, src, size));
		count = size;
	}
};

template <typename T>
struct DynamicArray {
	T* data;
	size_t count{};
	size_t capacity{};

	DynamicArray() : data(nullptr) {}

	explicit DynamicArray(const size_t size) {
		data = static_cast<T*>(__builtin_malloc(size * sizeof(T)));
		count = size;
		capacity = size;
	}

	DynamicArray(const size_t size, const size_t capacity) {
		data = static_cast<T*>(__builtin_malloc(size * sizeof(T)));
		count = size;
		this->capacity = capacity;
	}

	DynamicArray(T* src, const size_t size) {
		data = src;
		count = size;
		capacity = size;
	}

	DynamicArray(T* src, const size_t size, const size_t capacity) {
		data = src;
		count = size;
		this->capacity = capacity;
	}

	void push(const T& obj) {
		if (data == nullptr) {
			count = 0;
			capacity = 1;
			data = static_cast<T*>(__builtin_malloc(count * sizeof(T)));
			data[count++] = obj;
			return;
		}
		if (count < capacity) {
			data[count] = obj;
			count++;
		} else {
			if (capacity != 0) capacity *= 2;
			else capacity = 1;
			data = static_cast<T*>(realloc(data, capacity * sizeof(T)));
			data[count++] = obj;
		}
	}
};

#endif //BASE_ARRAY_H
