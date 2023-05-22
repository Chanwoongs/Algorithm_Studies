#include <iostream>

using namespace std;

int main()
{
    int size, num;
    
    cin >> size >> num;
    
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        
        if (temp < num) cout << temp << ' '; 
    }
}