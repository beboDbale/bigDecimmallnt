#include "bigDecimmallnt.h"

bool BigDecimalInt::validateNumber(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] == '+' || s[i] == '-') && i == 0)continue;
        if (!isdigit(s[i]))return false;
    }
    return true;
}

BigDecimalInt::BigDecimalInt() {
    number = "0";
    sign = '+';
}

BigDecimalInt::BigDecimalInt(string s) {
    // Check Number
    while (!validateNumber(s)) {
        cout << "Invalid input. Please enter valid number.\n";
    }
    number = s;
    sign = number[0];
    number.erase(0, 1);
}

BigDecimalInt::BigDecimalInt(long long n) {
    number = to_string(n);
    if(n<0)sign = '-';
    else sign = '+';
    number.erase(0, 1);
}
