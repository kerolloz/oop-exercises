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
            exercise = Exercise(atoi(argv[1]));
            break;
        case 3:
            exercise = Exercise(atoi(argv[1]), atoi(argv[2]));
            break;
        default:
            cout << "ERROR max parameters: 2" << endl;
            return 0;
    }
    
    exercise.create();
    system("pause");
    return 0;
}