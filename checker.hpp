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
            int compilationState = system("g++ " + tester);
            return (compilationState)? Compilation::FAILED : Compilation::SUCCESS ;
        }
};