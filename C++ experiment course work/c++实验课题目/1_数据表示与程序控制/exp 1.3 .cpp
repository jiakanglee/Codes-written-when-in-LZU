#include <iostream>

using namespace std;
#define PI 3.14159
int main()
{
    double radius,high;
    double volume;
    cout << "please input two numbers:" << endl;
    cin >> radius >> high;

    volume = PI * radius * radius * high;
    cout << "radius:" << radius << " high:" << high <<endl;
    cout << "the volume is: " << volume <<endl;
    return 0;
}
