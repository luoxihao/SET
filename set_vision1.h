
#include "ordered_pair.h"
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

class SET;
class SET {
  private:
    set<int> Int;
    set<char> Char;
    set<string> Str;
    set<double> Double;
    set<ord> Ord;
    bool Empty;
    types Mytype;
    // types MyordType = NUll;

  public:
    SET() { Mytype = NUll; };
    SET(initializer_list<int> in) {
        Int.insert(in);
        Mytype = INT;
        Empty = false;
    };
    SET(initializer_list<char> ch) {
        Char.insert(ch);
        Mytype = CHAR;
        Empty = false;
    };
    SET(initializer_list<string> str) {
        Str.insert(str);
        Mytype = STRING;
        Empty = false;
    };
    SET(initializer_list<double> dou) {
        Double.insert(dou);
        Mytype = DOUBLE;
        Empty = false;
    };
    SET(initializer_list<ord> temp_ord) {
        Ord.insert(temp_ord);
        Mytype = ORD;
        Empty = false;
    };
    //****************************************
    ~SET(){};              //析构
    SET(const SET &Temp) { //拷贝构造
        Int = Temp.Int;
        Char = Temp.Char;
        Str = Temp.Str;
        Double = Temp.Double;
        Ord = Temp.Ord;
        Empty = Temp.Empty;
        Mytype = Temp.Mytype;
    };
    //*********************添加元素************************
    inline void push(int x) {
        Int.insert(x);
        Mytype = INT;
        Empty = false;
    };
    inline void push(char x) {
        Char.insert(x);
        Mytype = CHAR;
        Empty = false;
    };
    inline void push(double x) {
        Double.insert(x);
        Mytype = DOUBLE;
        Empty = false;
    };
    inline void push(string x) {
        Str.insert(x);
        Mytype = STRING;
        Empty = false;
    };
    inline void push(ord &x) {
        Ord.insert(x);
        // cout << *this << endl;
        Mytype = ORD;
        Empty = false;
    };
    //****************************************************
    SET operator+(const SET &temp); //并
    SET operator&(const SET &temp); //交
    void operator=(const SET &temp);
    friend istream &operator>>(istream &Cin, SET &S);
    friend ostream &operator<<(ostream &Cout, const SET &S);
    void Cartesian_Product(const SET &SETA, const SET &SETB); //笛卡尔积
    void Cartesian_Product_print(const SET &SETA,
                                 const SET &SETB);  //笛卡尔积输出
    void Global_relationship_Print();               //集合的全域关系
    void Identity_relationship_Print(); //集合的恒等关系
    void Empty_Relationship_Print();                //空关系
};
void SET::Empty_Relationship_Print() { cout << "{}" << endl; }

void SET::Identity_relationship_Print() {//恒等
    SET temp;
    switch (Mytype) {
    case INT: {
        auto it = Int.begin();
        for (; it != Int.end(); it++) {
            ord t(*it, *it);
            temp.push(t);
        }
    } break;
    case DOUBLE: {
        auto it = Double.begin();
        for (; it != Double.end(); it++) {
            ord t(*it, *it);
            temp.push(t);
        }
    } break;
    case CHAR: {
        auto it = Char.begin();
        for (; it != Char.end(); it++) {
            ord t(*it, *it);
            temp.push(t);
        }
    }

    break;
    case STRING: {
        auto it = Str.begin();
        for (; it != Str.end(); it++) {
            ord t(*it, *it);
            temp.push(t);
        }
    } break;
    }
    cout << temp << endl;
}
void SET::Global_relationship_Print() {
    SET T_SET;
    SET T = *this;
    T_SET.Cartesian_Product_print(T, T);
}

//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------
void SET::Cartesian_Product(const SET &SETA, const SET &SETB) {
    switch (SETA.Mytype) {
    case INT:
        for (auto itA = SETA.Int.begin(); itA != SETA.Int.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case CHAR:
        for (auto itA = SETA.Char.begin(); itA != SETA.Char.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case DOUBLE:
        for (auto itA = SETA.Double.begin(); itA != SETA.Double.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case STRING:
        for (auto itA = SETA.Str.begin(); itA != SETA.Str.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case ORD:
        for (auto itA = SETA.Ord.begin(); itA != SETA.Ord.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    }
    return;
}

void SET::Cartesian_Product_print(const SET &SETA, const SET &SETB) { // AXB
    Ord.clear(); //保险 防止出现不可预知的错误
    switch (SETA.Mytype) {
    case INT:
        for (auto itA = SETA.Int.begin(); itA != SETA.Int.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case CHAR:
        for (auto itA = SETA.Char.begin(); itA != SETA.Char.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case DOUBLE:
        for (auto itA = SETA.Double.begin(); itA != SETA.Double.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case STRING:
        for (auto itA = SETA.Str.begin(); itA != SETA.Str.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    case ORD:
        for (auto itA = SETA.Ord.begin(); itA != SETA.Ord.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case CHAR:
                for (auto itB = SETB.Char.begin(); itB != SETB.Char.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case DOUBLE:
                for (auto itB = SETB.Double.begin(); itB != SETB.Double.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case STRING:
                for (auto itB = SETB.Str.begin(); itB != SETB.Str.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            case ORD:
                for (auto itB = SETB.Ord.begin(); itB != SETB.Ord.end();
                     itB++) {
                    ord Tord(*itA, *itB);
                    push(Tord);
                }
                break;
            }
        }
        break;
    }
    cout << *this << endl;
    return;
}
istream &operator>>(istream &Cin, SET &S) {
    int temp;
    Cin >> temp;
    types Ty = types(temp);
    S.Empty = false;
    switch (Ty) {
    case INT:
        int i;
        S.Mytype = INT;
        while (Cin >> i)
            S.Int.insert(i);

        break;
    case DOUBLE:
        double dou;
        S.Mytype = DOUBLE;
        while (Cin >> dou)
            S.Double.insert(dou);

        break;
    case CHAR:
        char ch;
        S.Mytype = CHAR;
        while (Cin >> ch)
            S.Char.insert(ch);

        break;
    case STRING: {
        string str;
        S.Mytype = STRING;
        while (Cin >> str)
            S.Str.insert(str);
        break;
    }
    }
    return Cin;
}

void SET::operator=(const SET &temp) { // 重载=
    Int = temp.Int;
    Char = temp.Char;
    Str = temp.Str;
    Double = temp.Double;
    Empty = temp.Empty;
    Mytype = temp.Mytype;
    Ord = temp.Ord;
}
SET SET::operator+(const SET &S) { //重载+ 并集
    SET temp = S;
    temp.Int.insert(Int.begin(), Int.end());
    temp.Char.insert(Char.begin(), Char.end());
    temp.Double.insert(Double.begin(), Double.end());
    temp.Str.insert(Str.begin(), Str.end());
    return temp;
}
SET SET::operator&(const SET &S) { // 重载&交集
    SET Temp;
    for (set<int>::iterator it = Int.begin(); it != Int.end(); it++)
        if (S.Int.count(*it))
            Temp.push(*it);
    for (set<char>::iterator it = Char.begin(); it != Char.end(); it++)
        if (S.Char.count(*it))
            Temp.push(*it);
    for (set<double>::iterator it = Double.begin(); it != Double.end(); it++)
        if (S.Double.count(*it))
            Temp.push(*it);
    for (set<string>::iterator it = Str.begin(); it != Str.end(); it++)
        if (S.Str.count(*it))
            Temp.push(*it);
    return Temp;
}

ostream &operator<<(ostream &Cout, const SET &S) {
    Cout << "{";
    if (S.Mytype == ORD) {
        for (auto it = S.Ord.begin(); it != S.Ord.end(); it++) {
            if (it != S.Ord.begin())
                Cout << ",";
            Cout << *it;
        }
    }
    for (auto it = S.Int.begin(); it != S.Int.end(); it++) {
        if (it != S.Int.begin())
            Cout << ",";
        Cout << *it;
    }
    for (auto it = S.Char.begin(); it != S.Char.end(); it++) {
        if (it != S.Char.begin())
            Cout << ",";
        Cout << *it;
    }
    for (auto it = S.Double.begin(); it != S.Double.end(); it++) {
        if (it != S.Double.begin())
            Cout << ",";
        Cout << *it;
    }
    for (auto it = S.Str.begin(); it != S.Str.end(); it++) {
        if (it != S.Str.begin())
            Cout << ",";
        Cout << *it;
    }
    Cout << "}";
    return Cout;
}
