//
// Created by Ryan.Zurrin001 on 1/17/2022.
//
#include "Hacker.h"


int main () {
    vector<int> v = {1, 2, 3, 4, 5};
    auto n = v.size();
    cout << "left rotation: " << endl;
    printVector(rotLeft(v, 3));

    return 0;
}


