#ifndef MAIN_CPP_BIGDECIMALLNT_H
#define MAIN_CPP_BIGDECIMALLNT_H

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
using namespace std;

class BigDecimalInt {
private:
    string number;
    char sign;

    bool validateNumber(string);

public:
    BigDecimalInt operator+(BigDecimalInt);

    BigDecimalInt();

    BigDecimalInt(string);

    BigDecimalInt(long long);
};


#endif
