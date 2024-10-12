#include <iostream>
using namespace std;

int main() {
    float a = 5.26;
    float b = 8.27;

    cout << fixed;
    cout.precision(3);

    cout << a * b << '\n';
    return 0;
}