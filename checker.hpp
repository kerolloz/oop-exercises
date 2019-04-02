#include "flags.hpp"
#include <string>

class Checker{
    private:
        std::string tester;
        
    public:
        Checker(std::string test){
            this->tester = test;
        }
        Compilation compile(){
            std::string command = "g++ " + this->tester + " -o test";
            int compilationState = system(command.c_str());
            return (compilationState)? Compilation::FAILED : Compilation::SUCCESS ;
        }
        Test test(){
            std::string command = "./test";
            int returnValue = system(command.c_str());
            return (returnValue == 0)? Test::SUCCESS : Test::FAILED; // success
                
        }

};