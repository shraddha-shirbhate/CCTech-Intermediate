#include <iostream>
using namespace std;
class SimpleIntrest{
  public:
    int p, t;
    float r;
    SimpleIntrest(int p, float r, int t){
        this->p = p;
        this->r = r; 
        this->t = t;
    }
    float calcSI(){
        float SI = (p*r*t)/100;
        return SI;
    }
};

int main() {
    SimpleIntrest si(1000, 10, 2);
    cout<<"Simple Interest is: "<<si.calcSI()<<endl;
    return 0;
}
