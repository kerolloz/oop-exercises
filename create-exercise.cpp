#include <iostream>
#include "exercise.hpp"
#define endl '\n'

using namespace std;



int main (int argc, char** argv) {

    Exercise exercise;
    switch (argc){
        case 1:
            break;
        case 2:
            exercise = Exercise(stoi(argv[1]));
            break;
        case 3:
            exercise = Exercise(stoi(argv[1]), stoi(argv[2]));
            break;
        default:
            cout << "ERROR max parameters: 2" << endl;
            return 0;
    }
    
    exercise.create();

}