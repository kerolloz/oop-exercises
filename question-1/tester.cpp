#include <bits/stdc++.h>
#include "solution.cpp"

#define endl '\n'

using namespace std;

int main (){
    Point p1(5, 5);
    Point p2(7, 7);
    if(p1.getDistance(p2) == int(sqrt(8)))
        return 0;
    else 
        return 1;
}
