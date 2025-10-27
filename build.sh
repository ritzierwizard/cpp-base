files=$(find . -type f -name "*.cpp")
g++ $files -o $1 -g -I=include/core
