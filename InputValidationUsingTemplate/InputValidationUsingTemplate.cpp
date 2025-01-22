#include <iostream>
#include "clsInputValidation.h"

using namespace std;


int main() {
    cout << clsInputValidate::IsNumberBetween <int>(5, 3, 7) << endl;
    cout << clsInputValidate::IsNumberBetween <float>(5.3, 3.2, 7.6) << endl;
    cout << clsInputValidate::IsNumberBetween <double>(10.4, 5.5, 18.8) << endl;

    cout << "\nEnter Int Number : ";
    cout << clsInputValidate::ReadNumber<int>() << endl;
    cout << "\nEnter Float Number : ";
    cout << clsInputValidate::ReadNumber<float>() << endl;
    cout << "\nEnter Double Number : ";
    cout << clsInputValidate::ReadNumber<double>() << endl;

    cout << "\nEnter Int Number Between 1 & 10 : ";
    cout << clsInputValidate::ReadNumberBetween<int>(1, 10);
    cout << "\nEnter Int Number Between 1.8 & 10.8 : ";
    cout << clsInputValidate::ReadNumberBetween<float>(1.8, 10.8);
    cout << "\nEnter float Number Between 1.3 & 10.5 : ";
    cout << clsInputValidate::ReadNumberBetween<double>(1.3, 10.5);

    return 0;
}