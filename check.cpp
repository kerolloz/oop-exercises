#include <iostream>
#include <cstring>
#include "checker.hpp"
#define endl '\n'

using namespace std;

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

int main ()
{
    string input;
    cout << "Please enter the number(s) of the question(s) you want to verify \n"
            "comma separated e.g: 1,2,3\n"
            ">> ";
    cin >> input;
    char * pch = strtok (const_cast<char*>(input.c_str()),",");
    while (pch != nullptr)
    {
        verify(stoi(pch));
        pch = strtok (nullptr, ",");
    }

    return 0;
} 

