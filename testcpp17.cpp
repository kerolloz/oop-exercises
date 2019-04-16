
#include <filesystem>

 
namespace fs = std::filesystem;

int main()
{
    // create files of different kinds
    fs::create_directory("sandbox");
    return 0;
}