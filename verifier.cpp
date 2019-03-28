#include<iostream>
#include "checker.hpp"

using namespace std;

int main (int argc, char* argv[])
{
    if(argc == 2){
        // the second parameter is the question number to be verified
        int questionNumber = stoi(string(argv[1]));
        string questionDir = "question-" + string(argv[1]) + "/";
        Checker c(questionDir + "solution.cpp", questionDir + "tester.cpp");
        if(Compilation::SUCCESS == c.compile() && Test::SUCCESS == c.test())
            cout << "Correct Answer\n";
        else
            cout << "Wrong Answer.\nTry Harder!\n";
        
            
    }else{
        cout << "Please add the question number to be provide as a parameter\n";
        return 1;
    }

    return 0;
} 

