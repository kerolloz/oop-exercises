#include <iostream>
#include "exercise.hpp"
#define endl '\n'

using namespace std;



int main (int argc, char** argv) {
    Exercise exercise;
    Exercise::folderNameTemplate = "exercise-";
    switch (argc){
        case 1:
            exercise();
            break;
        case 2:
            exercise(stoi(argv[1]));
            break;
        case 3:
            exercise(stoi(argv[1]), stoi(argv[2]));
            break;
        default:
            cout << "Please provide a parameter or 2";
            return 0;
    }
    exercise.create();

}