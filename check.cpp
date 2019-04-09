#include <iostream>
#include <cstring>
#include <sstream>
#include "checker.hpp"
#define endl '\n'

using namespace std;

 template < typename T > std::string to_string( const T& n ){
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

void verify(int questionNumber) {
    string exercisesDir = "exercises/";
    string questionDir = "exercise-" + to_string(questionNumber) + "/";
    Checker c(exercisesDir + questionDir + "tester.cpp");
    cout << "Testing Question #"  <<  questionNumber << ":" << endl;
    if(Compilation::SUCCESS == c.compile() && Test::SUCCESS == c.test())
        cout << "\tCORRECT Answer!\n";
    else
        cout << "\tWRONG Answer.\n"
                "\tTry Harder!\n";
}

int main (int argc, char ** argv)
{
    string input;
    if(argc == 1){
        cout << "Please enter the number(s) of the question(s) you want to verify \n"
                "comma separated e.g: 1,2,3\n"
                ">> ";
        cin >> input;
          
    }else if(argc == 2){
        input = argv[1];
    }

    char * pch = strtok (const_cast<char*>(input.c_str()),",");

    while (pch != nullptr) {
        verify(atoi(pch));
        pch = strtok (nullptr, ",");
    } 

    return 0;
} 

