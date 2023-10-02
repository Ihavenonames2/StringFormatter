#include "StringFormatter.h"
#include <iostream> 
#include <sstream> 

int main()
{
    
    std::cout << StringFormatter("Hello {:who}, its very {:weather}", { {":who", "1"}, {":weather", "sunny"}}) << std::endl;
    std::cout << StringFormatter("Hello {:CODEFORWORD1}, its very {:CODEFORWORD2}", { {":CODEFORWORD1", "Nastya"}, {":CODEFORWORD2", "sunny"} });
    return 0;
}