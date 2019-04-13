#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <boost/filesystem.hpp>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
 
namespace fs = std::boost::filesystem;

int main()
{
    // create files of different kinds
    fs::create_directory("sandbox");
    return 0;
}