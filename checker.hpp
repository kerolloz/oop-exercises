#include <utility>

#include "flags.hpp"
#include <stdlib.h>

using namespace std;

class Checker{
    private:
        string tester;
        string compilerExecutable;
    public:

        explicit Checker(string test) {
            this->tester = move(test);

            if(const char* env_cpp_compiler = std::getenv("CPP_COMPILER"))
                compilerExecutable = env_cpp_compiler;
            else
                cout << "ERROR: Please set your CPP_COMPILER env variable!\n",
                exit(-1);
        }

        Compilation compile(){
            std::string command = this->compilerExecutable + " " + this->tester + " -o test";
            int compilationState = system(command.c_str());
            return (compilationState)? Compilation::FAILED : Compilation::SUCCESS ;
        }

        Test test(){
            std::string command = "./test";
            int returnValue = system(command.c_str());
            system("rm ./test"); // remove the test binary after testing
            return (returnValue == 0)? Test::SUCCESS : Test::FAILED; 
                
        }

};