#include "bigDecimalInt.h"


// Private functions

// Getting the size
int BigDecimalInt::size(BigDecimalInt &num) {
    if (num.number[0] == '+' || num.number[0] == '-')
        return num.number.length() - 1;
    else
        return num.number.length();
}

// Check if string is valid or not
bool BigDecimalInt::validateNumber(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            if ((s[i] == '+' || s[i] == '-') && i == 0)continue;
            else return false;
        }
    }
    return true;
}

int BigDecimalInt::compare(string number1, string number2) {
    if(number1 > number2) return 1;
    if(number1 < number2) return -1;
    return 0;
}


// add two numbers (strings)
string BigDecimalInt::sum(string number1, string number2) {
    string result;
    if (number1 < number2)swap(number1, number2);
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    int carry = 0;
    for (int i = 0; i < number2.size(); ++i) {
        int digit = (number2[i] - '0') + (number1[i] - '0') + carry;
        result.push_back(digit % 10 + '0');
        carry = digit / 10;
    }

    for (int i = number2.size(); i < number1.size(); ++i) {
        int digit = number1[i] - '0' + carry;
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
    if (number1 < number2)swap(number1, number2);
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());
    int carry = 0;
    for (int i = 0; i < number2.size(); i++) {
        int sub = ((number1[i] - '0') - (number2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        result.push_back(sub + '0');
    }

    for (int i = number2.size(); i < number1.size(); i++) {
        int sub = ((number1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;

        result.push_back(sub + '0');
    }
    reverse(result.begin(), result.end());

    return result;
}


// Constructors
BigDecimalInt::BigDecimalInt() {
    // Default values
    number = "0";
    sign = '+';
}

BigDecimalInt::BigDecimalInt(string decStr) {
    // Check Number
    while (!validateNumber(decStr)) {
        cout << "Invalid input. Please enter valid number.\n";
        // user should try to enter number again
    }
    number = decStr;
    if (isdigit(number[0]))sign = '+';
    else {
        sign = number[0];
        number.erase(0, 1);
    }
}

BigDecimalInt::BigDecimalInt(long long decInt) {
    if (decInt < 0)sign = '-';
    else sign = '+';
    number = to_string(abs(decInt));
    if (!isdigit(number[0]))number.erase(0, 1);
}

// Operators Overloading

ostream &operator<<(ostream &out, const BigDecimalInt &number) {

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
        else if (compare(number, anotherDec.number) == 1)result.sign = sign;
        else result.sign = '+';
    }
    return result;
}

BigDecimalInt BigDecimalInt::operator-(const BigDecimalInt &anotherDec) {
    BigDecimalInt result;
    if (sign == '+' && anotherDec.sign == '+') {
        result.number = subtract(number, anotherDec.number);
        if (number >= anotherDec.number)result.sign = '+';
        else result.sign = '-';
    }
    else if(sign=='+'&&anotherDec.sign == '-'){
        result.number = sum(number, anotherDec.number);
        result.sign = '+';
    }
    else if(sign=='-'&&anotherDec.sign=='+'){
        result.number = sum(number, anotherDec.number);
        result.sign = '-';
    }
    else{
        result.number = subtract(number, anotherDec.number);
        if(number>anotherDec.number)result.sign = '-';
        else result.sign = '+';
    }
    return result;
}

bool operator>(const BigDecimalInt &number1, const BigDecimalInt &number2) {
    if (number1.sign == number2.sign) {
        if (number1.sign == '+') {
            if (number1.number.size() > number2.number.size())return true;
            else if (number1.number.size() < number2.number.size())return false;
            else {
                for (int i = 0; i < number1.number.size(); ++i) {
                    if (number1.number[i] == number2.number[i])continue;
                    else if (number1.number[i] > number2.number[i])return true;
                    else return false;
                }
            }
        } else {
            if (number1.number.size() > number2.number.size()) {
                return false;
            } else if (number1.number.size() < number2.number.size()) {
                return true;
            } else {
                for (int i = 0; i < number1.number.size(); ++i) {
                    if (number1.number[i] == number2.number[i])continue;
                    else if (number1.number[i] > number2.number[i])return false;
                    else return true;
                }
            }
        }
    } else if (number1.sign == '-')return false;
    else return true;
    return false;
}

bool operator<(const BigDecimalInt &number1, const BigDecimalInt &number2) {
    if (number1.sign == number2.sign) {
        if (number1.sign == '+') {
            if (number1.number.size() > number2.number.size())return false;
            else if (number1.number.size() < number2.number.size())return true;
            else {
                for (int i = 0; i < number1.number.size(); ++i) {
                    if (number1.number[i] == number2.number[i])continue;
                    if (number1.number[i] > number2.number[i])return false;
                    else return true;
                }
            }
        } else {
            if (number1.number.size() > number2.number.size())return true;
            else if (number1.number.size() < number2.number.size())return false;
            else {
                for (int i = 0; i < number1.number.size(); ++i) {
                    if (number1.number[i] == number2.number[i])continue;
                    if (number1.number[i] > number2.number[i])return true;
                    else return false;
                }
            }
        }
    } else if (number1.sign == '-')return true;
    else return false;
    return false;
}

bool operator==(const BigDecimalInt &number1, const BigDecimalInt &number2) {
    return (number1.number == number2.number) && (number1.sign == number2.sign);
}

BigDecimalInt BigDecimalInt::operator=(const BigDecimalInt &anotherDec) {
    // check number first
    number = anotherDec.number;
    sign = anotherDec.sign;
    return number;
}

