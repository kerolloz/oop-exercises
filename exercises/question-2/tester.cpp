#include <iostream>
#include "solution.cpp"

using namespace std;

int main() {

    Time t1(1, 30, 25), t2(2, 22, 10);
    Time t3;

    t3.Add(t1, t2);
    
    if(t3.hours == 4 && t3.min == 30 && !t3.second) return 0;
    else return 1;
}