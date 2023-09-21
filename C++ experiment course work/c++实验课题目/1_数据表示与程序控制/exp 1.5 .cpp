#include <iostream>

using namespace std;

int main()
{
  int operand1,operand2;
  char operator1;
  cout << "Please input arithmetic expression:" << endl;
  cin >> operand1 >> operator1 >> operand2;
  double result;
  while(operand1 != 0 && operator1 !='0' && operand2 != 0)
    {
          switch(operator1)
        {
          case '+':
          result = operand1 + operand2 ;
          cout << "output is as follows:" << endl;
          cout << operand1 << operator1 << operand2 << '=' << result << endl;
          break;
          case '-':
          result = operand1 - operand2 ;
          cout << "output is as follows:" << endl;
          cout << operand1 << operator1 << operand2 << '=' << result << endl;
          break;
          case '*':
          result = operand1 * operand2 ;
          cout << "output is as follows:" << endl;
          cout << operand1 << operator1 << operand2 << '=' << result << endl;
          break;
          case '/':
          result = operand1 / operand2 ;
          cout << "output is as follows:" << endl;
          cout << operand1 << operator1 << operand2 << '=' << result << endl;
          break;
          default:
          break;
        }
          cout << "Please input arithmetic expression:" << endl;
          cin >> operand1 >> operator1 >> operand2;
   }
    return 0;
}
