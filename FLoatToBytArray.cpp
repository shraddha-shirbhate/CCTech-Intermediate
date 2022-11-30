#include <iostream>

using namespace std;

union my_float{
    unsigned char buffer[4];
    float fl;
};

int main(int argc,char* argv[])
{
    union my_float temp;
    if(argc==2)
    {
        temp.fl = stof(argv[1]);
        for(char ch:temp.buffer)
        cout<< (int)ch << " ";
        cout << endl;
    }
    else if(argc==5)
    {
        temp.buffer[0]=stof(argv[2]);
        temp.buffer[1]=stof(argv[3]);
        temp.buffer[2]=stof(argv[4]);
        temp.buffer[3]=stof(argv[5]);
        cout << temp.fl;
    }
    return EXIT_SUCCESS;
}