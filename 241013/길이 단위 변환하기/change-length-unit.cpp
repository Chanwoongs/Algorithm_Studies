#include <iostream>
using namespace std;

int main() {
    float ft = 30.48;
    float mi = 160934;

    float a = 9.2;
    float b = 1.3;

    cout << fixed;
    cout.precision(1);

    cout << a << "ft = " << ft * a << "cm\n";
    cout << b << "mi = " << mi * b << "cm\n";

    return 0;
}