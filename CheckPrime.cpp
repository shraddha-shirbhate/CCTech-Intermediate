#include <iostream>
#include <assert.h>
using namespace std;

bool isPrime(int n){
    //cout<<"Enter a number to check whether it is Prime or not: ";
    //cin>>n;
    
    for(int i=2; i<=n/2; i++){
        if(n%i==0){
            //cout<<"NOT PRIME";
            return false;
            break;
        }
        else{
            //cout<<"PRIME"<<endl;
            return true;
        }
    }
    return true;
}

int main()
{  
    assert(!isPrime(6));
    assert(isPrime(5));
    assert(isPrime(7));
    return 0;
}