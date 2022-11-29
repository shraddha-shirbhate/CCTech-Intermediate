# include <iostream>
using namespace std;

int main() {

  char op;
  int a, b;

  cout << "Enter operator: +, -, *, /, %: ";
  cin >> op;
  cout << "Enter First operand: ";
  cin >> a;
  cout << "Enter Second operand: ";
  cin >> b;
  
  switch(op) {
    case '+':
      cout << a <<" + "<< b <<" = "<< a + b;
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