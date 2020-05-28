#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;
enum types { INT, CHAR, STRING, DOUBLE, ORD, NUll };
class ord {
  private:
    int *I[2];
    char *CH[2];
    string *STR[2];
    double *DOU[2];
    types type1, type2;

  public:
    // bool operator<(const ord &b) const;
    ord() {
        type1 = NUll;
        type2 = NUll;
    };
    friend ostream &operator<<(ostream &os, const ord &op);
    template <typename T1, typename T2> ord(T1 t1, T2 t2);
    ~ord(){}; //��������

    size_t OPHash() const; //��ż�����������������ڲ�ͬ��ż�����ıȽ�
    bool operator<(const ord &op) const {
        return (OPHash() < op.OPHash());
    }; //���ط���<
};
ostream &operator<<(ostream &os, const ord &op) {
    os << "<";
    switch (op.type1) {
    case INT:
        os << *op.I[0];
        break;
    case DOUBLE:
        os << *op.DOU[0];
        break;
    case STRING:
        os << *op.STR[0];
        break;
    case CHAR:
        os << *op.CH[0];
    }
    os << ",";
    switch (op.type2) {
    case INT:
        os << *op.I[1];
        break;
    case DOUBLE:
        os << *op.DOU[1];
        break;
    case STRING:
        os << *op.STR[1];
        break;
    case CHAR:
        os << *op.CH[1];
    }
    os << ">";
    return os;
}

// bool ord::operator<(const ord &b) const {
//     if (type1 == b.type1) {
//         return type2 < b.type2;
//     } else
//         return type1 < b.type1;
// }

template <typename T1, typename T2> ord::ord(T1 t1, T2 t2) {
    const type_info &IInfo = typeid(int);
    const type_info &CInfo = typeid(char);
    const type_info &StrInfo = typeid(string);
    const type_info &DOUInfo = typeid(double);
    const type_info &t1info = typeid(t1);
    const type_info &t2info = typeid(t2);
    T1 *tt1 = new T1;
    T2 *tt2 = new T2;
    *tt1 = t1;
    *tt2 = t2;
    I[0] = nullptr;
    I[1] = nullptr;
    CH[0] = nullptr;
    CH[1] = nullptr;
    STR[0] = nullptr;
    STR[1] = nullptr;
    DOU[0] = nullptr;
    DOU[1] = nullptr;
    if (t1info == IInfo) {
        type1 = INT;
        I[0] = (int *)tt1;

    } else if (t1info == CInfo) {
        type1 = CHAR;
        CH[0] = (char *)tt1;
    } else if (t1info == StrInfo) {
        type1 = STRING;
        STR[0] = (string *)tt1;
    } else if (t1info == DOUInfo) {
        type1 = DOUBLE;
        DOU[0] = (double *)tt1;
    }

    if (t2info == IInfo) {
        type2 = INT;
        I[1] = (int *)tt2;

    } else if (t2info == CInfo) {
        type2 = CHAR;
        CH[1] = (char *)tt2;
    } else if (t2info == StrInfo) {
        type2 = STRING;
        STR[1] = (string *)tt2;
    } else if (t2info == DOUInfo) {
        type2 = DOUBLE;
        DOU[1] = (double *)tt2;
    }
}

size_t ord::OPHash() const {
    size_t s = type1 * 10000 + type2 * 100000;
    switch (type1) {
    case INT:
        s += *I[0] * 200;
        break;
    case CHAR:
        s += *CH[0] * 400;
        break;
    case STRING:
        s = (s + STR[0]->length() + STR[0]->at(0)) * 1000;
        break;
    case DOUBLE:
        s += *DOU[0] * 600;
        break;
    case NUll:
        break;
    default:
        break;
    }
    switch (type2) {
    case INT:
        s += *I[1] * 200;
        break;
    case CHAR:
        s += *CH[1] * 400;
        break;
    case STRING:
        s = (s + STR[1]->length() + STR[1]->at(0)) * 1000;
        break;
    case DOUBLE:
        s += *DOU[1] * 600;
        break;
    case NUll:
        break;
    default:
        break;
    }
    return s;
}
