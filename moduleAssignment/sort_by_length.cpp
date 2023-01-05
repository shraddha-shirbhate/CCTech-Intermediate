#include <iostream>
#include <vector>
#include <string>
#include "sort_string_by_length.h"

int main(int argc, char* argv[])
{
    std::string line;
    std::vector<std::string> lines;

    while(std::getline(std::cin,line))  // input lines to vector
        lines.push_back(line);
    
    lines = sort_string_by_length(lines);   // sort by length

    for(auto line:lines)    // print result
    std::cout<<line<<std::endl;
    
    return EXIT_SUCCESS;
}