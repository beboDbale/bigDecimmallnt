#ifndef MAIN_CPP_BIGDECIMMALLNT_H
#define MAIN_CPP_BIGDECIMMALLNT_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigDecimalInt {
private:
    string number;
    char sign;

    string sum(string, string);

    string subtract(string, string);

    bool validateNumber(string);

public:
    // Constructors
    BigDecimalInt();

    BigDecimalInt(string);

    BigDecimalInt(long long);

    // Operators Overloading
    BigDecimalInt operator+(const BigDecimalInt &);

};


#endif
