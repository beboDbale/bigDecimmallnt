#ifndef MAIN_CPP_BIGDECIMALLNT_H
#define MAIN_CPP_BIGDECIMALLNT_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigDecimalInt {

    friend ostream &operator<<(ostream &, BigDecimalInt);

private:
    string number;
    char sign;

    string sum(string, string);

    string subtract(string, string);

    bool validateNumber(string);

    int compare(string, string);


public:
    // Constructors
    BigDecimalInt();

    BigDecimalInt(string decStr);

    BigDecimalInt(long long decInt);

    // Operators Overloading
    BigDecimalInt operator+(const BigDecimalInt &);

    BigDecimalInt operator-(const BigDecimalInt &);

};


#endif
