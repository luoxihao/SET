#include "set_vision1.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
//  enum types { INT, CHAR, STRING, DOUBLE };
int main() {
    SET SET1, SET2;
    ifstream input1, input2;
    input1.open("math/SET_ordered couple_文春改2/data_set1.txt", ios::in);
    input2.open("math/SET_ordered couple_文春改2/data_set2.txt", ios::in);
    if (input1.is_open())
        input1 >> SET1;
    else
        cout << "data_set1 is not open" << endl;
    if (input2.is_open())
        input2 >> SET2;
    else
        cout << "data_set2 is not open" << endl;
    // cout << SET1 << endl;
    // cout << SET2 << endl;
    // SET SET3 = SET1 + SET2;
    // SET SET4 = SET1 & SET2;
    // cout << SET3 << endl;
    // cout << SET4 << endl;
    // cout << SET1 << endl;
    // cout << SET2 << endl;

    SET SET3;
    SET3.Cartesian_Product(SET1, SET2);
    // SET3.ORDOUT();
    cout << SET3 << endl;

    // SET SETANS = Cartesian_Product(T_ord, T_ord2);
    // SETANS.push(T_ord);
    // cout << SETANS << endl;
    // cout << T_ord;
    // for (auto it = SETANS.Ord.begin(); it != SETANS.Ord.end(); it++) {
    //     cout << *it;
    // }
    // cout << SETANS << endl;
    return 0;
}
