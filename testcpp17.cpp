#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
 
namespace fs = std::filesystem;

int main()
{
    // create files of different kinds
    fs::create_directory("sandbox");
    return 0;
}