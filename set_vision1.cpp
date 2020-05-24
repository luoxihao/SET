#include "set_vision1.h"

#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
    SET SET1, SET2;
    ifstream input1, input2;
    input1.open("math/data_set1.txt", ios::in);
    input2.open("math/data_set2.txt", ios::in);
    if (input1.is_open())
        input1 >> SET1;
    else
        cout << "data_set1 is not open" << endl;
    if (input2.is_open())
        input2 >> SET2;
    else
        cout << "data_set2 is not open" << endl;
    cout << SET1 << endl;
    cout << SET2 << endl;
    SET SET3 = SET1 + SET2;
    SET SET4 = SET1 & SET2;
    cout << SET3 << endl;
    cout << SET4 << endl;

    return 0;
}