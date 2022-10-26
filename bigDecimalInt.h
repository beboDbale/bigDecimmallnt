#ifndef MAIN_CPP_BIGDECIMALLNT_H
#define MAIN_CPP_BIGDECIMALLNT_H

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

    int compare(string, string);


public:
    // Functions
    int getSize();

    char getSign();
    // Constructors
    BigDecimalInt();

    BigDecimalInt(string decStr);

    BigDecimalInt(long long decInt);

    // Operators Overloading
    BigDecimalInt operator+(const BigDecimalInt &);

    BigDecimalInt operator-(const BigDecimalInt &);

    friend bool operator>(const BigDecimalInt &number1, const BigDecimalInt &number2);

    friend bool operator<(const BigDecimalInt &number1, const BigDecimalInt &number2);

    friend bool operator==(const BigDecimalInt &number1, const BigDecimalInt &number2);

    friend ostream &operator<<(ostream &, const BigDecimalInt&);

    BigDecimalInt operator=(const BigDecimalInt&);

    friend string removeLeadingZeros(const string&);

};

#endif //MAIN_CPP_BIGDECIMALLNT_H

