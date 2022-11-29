#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double sqRoot(double x) {                                                         
    if ( x < 0 ){
        throw invalid_argument("sqrt received negative argument");
    }
    return sqrt(x);
}

int main() {
    double n;
    
    try {
        cout<<"Enter any number: ";
        cin>>n;
        double sqt = sqRoot(n);
        cout<<"SquareRoot of "<<n<<" is: "<<sqt<<endl;
    }
    catch (const exception& e) {
        cout << "Caught " << e.what() << endl;
    }
    return 0;
}