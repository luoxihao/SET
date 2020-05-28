#include "set_vision1.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
//  enum types { INT, CHAR, STRING, DOUBLE };
int main() {
    SET SET1, SET2;
    ifstream input1, input2;
    input1.open("math/SET_ordered couple/data_set1.txt", ios::in);
    input2.open("math/SET_ordered couple/data_set2.txt", ios::in);
    if (input1.is_open())
        input1 >> SET1;
    else
        cout << "data_set1 is not open" << endl;
    if (input2.is_open())
        input2 >> SET2;
    else
        cout << "data_set2 is not open" << endl;
    cout << "SET1: " << SET1 << endl;
    cout << "SET2: " << SET2 << endl;
    SET SET3 = SET1 + SET2;
    SET SET4 = SET1 & SET2;
    cout << "SET1与SET2的并集为：" << SET3 << endl;
    cout << "SET1与SET2的交集为：" << SET4 << endl;
    SET SET5;
    cout << "SET1与SET2的笛卡尔积为：" << endl; //笛卡尔积
    SET5.Cartesian_Product(SET1, SET2);//两种输出方式Cartesian_Product_print()
    cout << SET5 << endl;
    SET SET6;
    cout << "SET1的全域关系为:" << endl; //全域
    SET1.Global_relationship_Print();
    SET SET7;
    cout << "SET1的恒等关系为:" << endl;
    SET1.Identity_relationship_Print(); //恒等

    cout << "SET1的空关系为:" << endl;
    SET1.Empty_Relationship_Print();
    return 0;
}
