#include <iostream> 
#include <vector> 
#include <regex>

std::string trim(const std::string& input, char ch, char ch2)
{
    std::string temp = input;

    for (auto i = temp.begin(); i != temp.end();)
    {
        if (*i != ch && *i != ch2)
            break;
        i = temp.erase(i);
    }

    for (auto i = temp.end(); i != temp.begin();)
    {
        --i;
        if (*i != ch && *i != ch2)
            break;
        temp.resize(temp.size() - 1);
    }

    return temp;
}

std::string StringFormatter(std::string mystr, std::vector<std::pair<std::string, std::string>> vec)
{
    std::string str = mystr;
    while(1)
    {
        std::regex regexp("\\{:[a-zA-Z0-9]+\\}");
        std::smatch m;
        std::regex_search(str, m, regexp);
        std::string match;
        match = trim(m[0], '{', '}');
        std::string result;

        for (int i = 0; i < vec.size(); i++)
        {
            
            if (vec[i].first == match)
            {
                result = regex_replace(str, regexp, vec[i].second, std::regex_constants::format_first_only);
            }
        }

        str = result;
        regex_search(str, m, regexp);
        if (m.empty())
        {
            return result;
            break;
        }
    }
    
   
}



int main()
{
    std::cout << StringFormatter("Hello {:who}, its very {:weather}", { {":who", "Nastya"}, {":weather", "sunny"} }) << std::endl;
    std::cout << StringFormatter("Hello {:CODEFORWORD1}, its very {:CODEFORWORD2}", { {":CODEFORWORD1", "Nastya"}, {":CODEFORWORD2", "sunny"} });
    return 0;
}