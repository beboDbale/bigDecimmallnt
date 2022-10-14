#include "bigDecimalInt.h"
#include <iostream>
#include <string>

using namespace std;


// Private functions

// Check if string is valid or not
bool BigDecimalInt::validateNumber(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if(!isdigit(s[i])){
            if((s[i]=='+'||s[i]=='-')&&i==0)continue;
            else return false;
        }
    }
    return true;
}



int BigDecimalInt::compare(string number1, string number2) {
    // number1 > number2 return 1
    // number1 < number2 return -1
    // return 0
}

// add two numbers (strings)
string BigDecimalInt::sum(string number1, string number2) {
    string result;
    if (number1.size() < number2.size())swap(number1, number2);
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    int carry = 0, digit;
    for (int i = 0; i < number2.size(); ++i) {
        digit = (number2[i] - '0') + (number1[i] - '0') + carry;
        result.push_back(digit % 10 + '0');
        carry = digit / 10;
    }

    for (int i = number2.size(); i < number1.size(); ++i) {
        digit = number1[i] - '0' + carry;
        result.push_back(digit % 10 + '0');
        carry = digit / 10;
    }

    if (carry > 0) {
        string car = to_string(carry);
        reverse(car.begin(), car.end());
        for (int i = 0; i < car.size(); ++i) {
            result.push_back(car[i]);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

// get the difference between 2 numbers (strings)
string BigDecimalInt::subtract(string number1, string number2) {
    string result;
    if (number1.size() < number2.size())swap(number1, number2);
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());
    int carry = 0, digit;

    return result;
}


// Constructors
BigDecimalInt::BigDecimalInt() {
    // Default values
    number = "0";
    sign = '+';
}

BigDecimalInt::BigDecimalInt(string s) {
    // Check Number
    while (!validateNumber(s)) {
        cout << "Invalid input. Please enter valid number.\n";
        // user should try to enter number again
    }
    number = s;
    if(isdigit(number[0]))sign = '+';
    else sign = number[0];
    number.erase(0, 1);
}

BigDecimalInt::BigDecimalInt(long long n) {
    if (n < 0)sign = '-';
    else sign = '+';
    number = to_string(n);
    if (!isdigit(number[0]))number.erase(0, 1);
}

// Operators Overloading

ostream &operator<<(ostream &out, BigDecimalInt number) {

    out << number.sign << number.number;
    return out;
}

BigDecimalInt BigDecimalInt::operator+(const BigDecimalInt &anotherDec) {
    BigDecimalInt result;
    // Same sign --> get the sum of the 2 numbers and add sign to the result
    if (sign == anotherDec.sign) {
        result.number = sum(number, anotherDec.number);
        result.sign = sign;
    }
        // different sign --> get the different between them
        // and add the sign of the largest number to the result
    else {
        result.number = subtract(number, anotherDec.number);
        if (compare(number, anotherDec.number) == -1)result.sign = anotherDec.sign;
        else if(compare(number, anotherDec.number) == 1)result.sign = sign;
        else result.sign = '+';
    }
    return result;
}

BigDecimalInt BigDecimalInt::operator-(const BigDecimalInt &anotherDec) {
    BigDecimalInt result;
    // Same sign --> get the different between the 2 numbers and add sign to the result
    if (sign == anotherDec.sign) {
        result.number = subtract(number, anotherDec.number);
        result.sign = sign;
    }
        // different sign --> get the sum of them
        // and add the sign of the largest number to the result
    else {
        result.number = sum(number, anotherDec.number);
    }
    return result;
}
