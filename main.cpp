//this project is to do operations on big decimal integers
//institute: Faculty of Computers And Artificial Intelligence Cairo University
//course: object oriented programming
//project name: big decimal integers
//professor: Dr. Mohamed El-ramly
//students:
//1- Belal Ahmed Eid 20210092
//2- Zeyad Ehab Maamoun El-Naggar 20211043
//3- Youssef Ahmed Zakaria 20210458

#include "functions.cpp"

int main() {
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    BigDecimalInt num6 = num3;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num4 << endl;
    cout << "num2 - num1 = " << num5 << endl;
    cout << "num9 = " << num6 << endl;
    cout << "num2 > num1 = " << (num2 > num1) << endl;
    cout << "num2 < num1 = " << (num2 < num1) << endl;
    cout << "num2 == num1 = " << (num2 == num1) << endl;
    cout << num2.getSign() << " " << num2 << " " << num2.getSize() << endl;
}
