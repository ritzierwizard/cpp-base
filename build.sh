files=$(find . -type f -name "*.cpp")
g++ $files -o $1 -g -I=include/core -std=gnu++23 -Wall -Werror -fno-delete-null-pointer-checks -fwrapv
