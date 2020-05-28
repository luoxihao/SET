
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

  public: //���캯��
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
    ~SET(){};              //��������
    SET(const SET &Temp) { //�������캯��
        Int = Temp.Int;
        Char = Temp.Char;
        Str = Temp.Str;
        Double = Temp.Double;
        Ord = Temp.Ord;
        Empty = Temp.Empty;
        Mytype = Temp.Mytype;
    };
    //*********************����Ԫ��************************
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
    SET operator+(const SET &temp); //��
    SET operator&(const SET &temp); //��
    void operator=(const SET &temp);
    friend istream &operator>>(istream &Cin, SET &S);
    friend ostream &operator<<(ostream &Cout, const SET &S);
    void Cartesian_Product(const SET &SETA, const SET &SETB); //�ѿ�����
    SET power();
    void ORDOUT();
};
void SET::ORDOUT() {
    cout << "cout be used" << endl;
    if (!Ord.empty()) {
        cout << "full";
    } else
        cout << "empty";
}
//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------
void SET::Cartesian_Product(const SET &SETA, const SET &SETB) { // AXB
    Mytype = ORD;
    // cout << SETA.Mytype << endl;
    // cout << SETB.Mytype << endl;
    // cout << INT << endl;
    switch (SETA.Mytype) { //�жϵ�һ��set������ ֮�����жϵڶ���������
    case INT:
        for (auto itA = SETA.Int.begin(); itA != SETA.Int.end(); itA++) {
            switch (SETB.Mytype) {
            case INT:
                for (auto itB = SETB.Int.begin(); itB != SETB.Int.end();
                     itB++) {
                    // cout << "Cartesian_Product" << endl;

                    ord Tord(*itA, *itB);
                    // cout << Tord << endl;
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

void SET::operator=(const SET &temp) { // =����
    Int = temp.Int;
    Char = temp.Char;
    Str = temp.Str;
    Double = temp.Double;
    Empty = temp.Empty;
    Mytype = temp.Mytype;
}
SET SET::operator+(const SET &S) { // +���� ����
    SET temp = S;
    temp.Int.insert(Int.begin(), Int.end());
    temp.Char.insert(Char.begin(), Char.end());
    temp.Double.insert(Double.begin(), Double.end());
    temp.Str.insert(Str.begin(), Str.end());
    return temp;
}
SET SET::operator&(const SET &S) { // &���� ����
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
