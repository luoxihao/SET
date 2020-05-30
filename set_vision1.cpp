#include "set_vision1.h"

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
//  enum types { INT, CHAR, STRING, DOUBLE };
int main() {
    SET SET1, SET2, SETpair1;
    ifstream input1, input2, input3;
    input1.open("math/SET_ordered couple/data_set1.txt", ios::in);
    input2.open("math/SET_ordered couple/data_set2.txt", ios::in);
    input3.open("math/SET_ordered couple/data_pair.txt", ios::in);
    if (input1.is_open())
        input1 >> SET1;
    else
        cout << "data_set1 is not open" << endl;
    if (input2.is_open())
        input2 >> SET2;
    else
        cout << "data_set2 is not open" << endl;
    if (input3.is_open())
        input3 >> SETpair1;
    else
        cout << "data_pair1 is not open" << endl;
    // cout << "SET1: " << SET1 << endl;
    // cout << "SET2: " << SET2 << endl;
    // SET SET3 = SET1 + SET2;
    // SET SET4 = SET1 & SET2;
    // cout << "SET1与SET2的并集为：" << SET3 << endl;
    // cout << "SET1与SET2的交集为：" << SET4 << endl;
    // SET SET5;
    // cout << "SET1与SET2的笛卡尔积为：" << endl; //笛卡尔积
    // SET1.Cartesian_Product_print(SET2);

    // //两种输出方式Cartesian_Product_print() cout << SET5 << endl; SET
    // cout << "SET1的全域关系为:" << endl; //全域
    // SET1.Global_relationship_Print();
    // SET SET7;
    // cout << "SET1的恒等关系为:" << endl;
    // SET1.Identity_relationship_Print(); //恒等

    // cout << "SET1的空关系为:" << endl; //空关系
    // SET1.Empty_Relationship_Print();
    // cout << "SET1的小于或等于的关系为;" << endl;
    // SET1.Less_or_equal_relationship_print(); //少于或等于

    // cout << "SET1的整除关系为:" << endl;
    // SET1.Divisive_relationship_print(); //整除关系

    // cout << SETpair1 << endl;
    SETpair1.Relation_matrix_print(); //关系矩阵图

    return 0;
}
