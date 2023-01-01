#pragma once
#include <iostream>
#ifndef verify
#define verify(cond)\
    do{\
        if(!(cond))\
            std::cerr<<__FILE__<<":"<<__LINE__<<": error: In function "<<__FUNCTION__<<", verification of condition \""<<#cond<<"\" failed.\n";\
    }while(0)
#endif