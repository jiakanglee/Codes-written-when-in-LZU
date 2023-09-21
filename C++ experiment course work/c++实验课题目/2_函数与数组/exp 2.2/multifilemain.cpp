#include <iostream>
#include "func.h"
using namespace std;




int main()
{
    long long n, r;
    cout << "please input the n and r:" << endl
        << "input 0,0 to end" << endl;
    cin >> n;
    cin >> r;
    while ((n != 0 && r != 0) || (n != 0 && r == 0)) {
        if (n < 1 || r < 0 || n < r) {
            cout << "invalid input,please input again:" << endl
                << "if you want to exit,don't input 0,0 for this time,wait for another instruction!" << endl;
            cin >> n >> r;
            continue;
        }
        float ans = factorial(n) / (factorial(r) * factorial(n - r));
        cout << "Your answer is:" << endl;
        cout << ans << endl;
        cout << "please input the n and r:" << endl
            << "input 0,0 to end" << endl;
        cin >> n >> r;
    }
    return 0;
}