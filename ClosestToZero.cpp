#include <iostream>
#include <cassert>
#include <algorithm>

int closestNumber(int list[],int length)
{
    int ans=list[0];

        int diff=abs(list[0]);
        for(int i=1;i<length;i++)
        {
            if(abs(list[i]) < diff)
            {
                ans=list[i];
                diff=abs(list[i]);
            }
            if(diff==abs(list[i]) && list[i]>ans)
                ans=list[i];
        }
        return ans;
}

int main(int argc, char* argv[])
{
    int list[]={-2,4,-3,5};
    assert(closestNumber(list,sizeof(list)/sizeof(int))==-2);
    int list1[]={-2,4,2,-3,5};
    assert(closestNumber(list1,sizeof(list1)/sizeof(int))==2);
    return EXIT_SUCCESS;
}