#include <iostream>

using namespace std;

int main()
{
    int N;
	cin >> N;

    if (N <= 780 && N >= 620) {
        cout<< "Red";
    }
    else if (N < 620 && N >= 590) {
        cout << "Orange";
    }
    else if (N <590 && N >= 570) {
        cout << "Yellow";
    }
    else if (N < 570 && N >= 495) {
        cout << "Green";
    }
    else if (N < 495 && N >= 450) {
        cout << "Blue";
    }
    else if (N < 450 && N >= 425) {
        cout << "Indigo";
    }
    else if (N < 425 && N >= 380) {
        cout << "Violet";
    }

	return 0;
}