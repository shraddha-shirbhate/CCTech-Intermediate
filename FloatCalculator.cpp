#include <float.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

# include <iostream>
using namespace std;

int main() {

  char op;
  int a, b, result;

  cout << "Enter operator: +, -, *, /, %: ";
  cin >> op;
  cout << "Enter First operand: ";
  cin >> a;
  cout << "Enter Second operand: ";
  cin >> b;
  
  switch(op) {
    case '+':
      result = a+b;
      if(a > 0 && b > 0 && result < 0) throw std::invalid_argument("Float Overflow");
      if(a < 0 && b < 0 && result > 0) throw std::invalid_argument("Float Underflow");
      cout << a <<" + "<< b <<" = "<< result;
      break;

    case '-':
      cout << a << " - " << b << " = " << a - b;
      break;

    case '*':
      cout << a << " * " << b << " = " << a * b;
      break;

    case '/':
        if(b==0){
            cout<<"Dvision operation could not be perfomed."<<endl;
            break;
        }else{
            cout << a << " / " << b << " = " << a / b;
        }
      break;
     
     case '%':
      cout << a << " % " << b << " = " << a % b;
      break;

    default:
      cout << "Error! operator is not correct";
      break;
  }

  return 0;
}
