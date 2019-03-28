#include "compiler.hpp"

class Checker{
    private:
        string solution;
        string tester;
        
    public:
        Checker(string sol, string test){
            this->solution = sol;
            this->tester = test;
        }
        Compilation compile(){
            string command = "g++ " + tester;
            int compilationState = system(command.c_str());
            return (compilationState)? Compilation::FAILED : Compilation::SUCCESS ;
        }
};