#include <zlib.h>
#include <iostream>
//#include<fmt\core.h>中文乱码错误或路径错误
int main() {
    const char* src = "Hello vcpkg!";
    uLong compressed_size = compressBound(strlen(src));
    Bytef* dest = new Bytef[compressed_size];
    compress(dest, &compressed_size, (const Bytef*)src, strlen(src));
    std::cout << "Compressed size: " << compressed_size << std::endl;
    delete[] dest;
    return 0;
}