#include <iostream>
using namespace std;

int main() {
    int a = 13;
    double b = 0.165000;

    cout << fixed;

    cout.precision(6);

    cout << a << " * " << b << " = " << a * b;


    return 0;
}