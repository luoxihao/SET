#include <bits/stdc++.h>

#include <iostream>
using namespace std;
enum types { INT, CHAR, STRING, DOUBLE };
class SET;
class SET {
   private:
    set<int> Int;
    set<char> Char;
    set<string> Str;
    set<double> Double;
    bool Empty;

   public:  //构造函数
    SET(){};
    SET(initializer_list<int> in) {
        Int.insert(in);
        Empty = false;
    }
    SET(initializer_list<char> ch) {
        Char.insert(ch);
        Empty = false;
    }
    SET(initializer_list<string> str) {
        Str.insert(str);
        Empty = false;
    }
    SET(initializer_list<double> dou) {
        Double.insert(dou);
        Empty = false;
    }
    //****************************************
    ~SET(){};               //析构函数
    SET(const SET& Temp) {  //拷贝构造函数
        Int = Temp.Int;
        Char = Temp.Char;
        Str = Temp.Str;
        Double = Temp.Double;
        Empty = Temp.Empty;
    }
    //*********************添加元素************************
    inline void push(int x) {
        Int.insert(x);
        Empty = false;
    }
    inline void push(char x) {
        Char.insert(x);
        Empty = false;
    }
    inline void push(double x) {
        Double.insert(x);
        Empty = false;
    }
    inline void push(string x) {
        Str.insert(x);
        Empty = false;
    }
    //****************************************************
    SET operator+(const SET& temp);  //并
    SET operator&(const SET& temp);  //交
    void operator=(const SET& temp);
    friend istream& operator>>(istream& Cin, SET& S);
    friend ostream& operator<<(ostream& Cout, const SET& S);
    SET power();  //幂集
};
istream& operator>>(istream& Cin, SET& S) {
    int temp;
    Cin >> temp;
    types Ty = types(temp);
    S.Empty = false;
    switch (Ty) {
        case INT:
            int i;
            while (Cin >> i) S.Int.insert(i);

            break;
        case DOUBLE:
            double dou;
            while (Cin >> dou) S.Double.insert(dou);

            break;
        case CHAR:
            char ch;
            while (Cin >> ch) S.Char.insert(ch);

            break;
        case STRING:
            string str;
            while (Cin >> str) S.Str.insert(str);
    }
}

ostream& operator<<(ostream& Cout, const SET& S) {
    Cout << "{";
    for (set<int>::iterator it = S.Int.begin(); it != S.Int.end(); it++) {
        if (it != S.Int.begin()) Cout << ",";
        Cout << *it;
    }
    for (set<char>::iterator it = S.Char.begin(); it != S.Char.end(); it++) {
        if (it != S.Char.begin()) Cout << ",";
        Cout << *it;
    }
    for (set<double>::iterator it = S.Double.begin(); it != S.Double.end();
         it++) {
        if (it != S.Double.begin()) Cout << ",";
        Cout << *it;
    }
    for (set<string>::iterator it = S.Str.begin(); it != S.Str.end(); it++) {
        if (it != S.Str.begin()) Cout << ",";
        Cout << *it;
    }
    Cout << "}";
    return Cout;
}
void SET::operator=(const SET& temp) {  // =重载
    Int = temp.Int;
    Char = temp.Char;
    Str = temp.Str;
    Double = temp.Double;
    Empty = temp.Empty;
}
SET SET::operator+(const SET& S) {  // +重载 并集
    SET temp = S;
    temp.Int.insert(Int.begin(), Int.end());
    temp.Char.insert(Char.begin(), Char.end());
    temp.Double.insert(Double.begin(), Double.end());
    temp.Str.insert(Str.begin(), Str.end());
    return temp;
}
SET SET::operator&(const SET& S) {  // &重载 交集
    SET Temp;
    for (set<int>::iterator it = Int.begin(); it != Int.end(); it++)
        if (S.Int.count(*it)) Temp.push(*it);
    for (set<char>::iterator it = Char.begin(); it != Char.end(); it++)
        if (S.Char.count(*it)) Temp.push(*it);
    for (set<double>::iterator it = Double.begin(); it != Double.end(); it++)
        if (S.Double.count(*it)) Temp.push(*it);
    for (set<string>::iterator it = Str.begin(); it != Str.end(); it++)
        if (S.Str.count(*it)) Temp.push(*it);
    return Temp;
}