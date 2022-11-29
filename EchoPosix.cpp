#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

string isEcho(int argv, char *argc[]){
    
    if(argv == 1){
        return "\n";
    }else{
        return argc[1] + '\n';
    }
   
    return "\n";
}

int main(int argv, char *argc[])
{
    assert(isEcho(1, argc) == "\n");
    assert(isEcho(2, argc) == argc[1] + '\n');
    //assert(isEcho(3, argc) == strcat(argc[1]) + argc[2] + '\n');
    
    return 0;
}