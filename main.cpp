#include <cstdio>

#include "array.h"

int main() {
	auto arr = DynamicArray<int>();
	arr.push(3);

	printf("%d\n", arr.data[0]);

	return 0;
}
