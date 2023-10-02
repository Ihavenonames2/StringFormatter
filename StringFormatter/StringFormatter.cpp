#include <iostream> 
#include <vector> 
#include <regex>

using namespace std;

string trim(const std::string& input, char ch, char ch2)
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
        *i = '\0';
    }

    return temp;
}

std::string StringFormatter(string mystr, std::vector<std::pair<std::string, std::string>> vec)
{
    int i = 0;
    std::string str = mystr;
    while(i < 5)
    {
        regex regexp("\\{:[a-zA-Z0-9]+\\}");
        smatch m;
        regex_search(str, m, regexp);
        string match;
        match = trim(m[0], '{', '}');
        string result;

        for (int i = 0; i < vec.size(); i++)
        {
            vec[i].first.resize(match.size());
            if (vec[i].first == match)
            {
                result = regex_replace(str, regexp, vec[i].second, std::regex_constants::format_first_only);
            }
        }

        str = result;
        i++;
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
    std::cout<<StringFormatter("a = {:abrakadabra}, {:baban}", { {":baban", "10"}, {":abrakadabra", "11"} });
    return 0;
}