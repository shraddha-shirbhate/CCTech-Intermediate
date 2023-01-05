#include <vector>
#include <map>
std::vector<std::string> sort_string_by_length(std::vector<std::string> lines)
{
    std::multimap<size_t,std::string> linesMap; // Multimap for sorting input strings

    for(auto line:lines)
    linesMap.insert({line.length(),line});
    
    lines.clear();  // clearing vector for reusing
    
    std::multimap<size_t,std::string>::iterator itr;    // get sorted list from
    for(auto itr = linesMap.begin(); itr!=linesMap.end(); ++itr)
        lines.push_back(itr->second);

    return lines;
}