#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(const std::string &csvLine, const char &separator)
{

    std::vector<std::string> tokens;
    std::string token;
    std::string::size_type start;
    std::string::size_type end;

    start = csvLine.find_first_not_of(separator);

    if (start == std::string::npos)
        return tokens;

    do
    {
        end = csvLine.find_first_of(separator, start);

        if (end == std::string::npos)
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        else
        {
            token = csvLine.substr(start, end - start);
        }
        start = end + 1;

        tokens.push_back(token);
    } while (end != std::string::npos);

    return tokens;
}

int main()
{

    std::string csvLine{"2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02184363,4.52654436"};

    std::string csvFileName{"20200317.csv"};
    std::ifstream csvFile{csvFileName};

    if (csvFile.is_open())
    {

        while (std::getline(csvFile, csvLine))
        {
            std::cout << csvLine << std::endl;
            std::vector<std::string> tokens = tokenise(csvLine, ',');

            if (tokens.size() != 5)
            {
                continue;
            }

            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                 std::cout<<"Price : "<<price<<" Amount : "<<amount<<std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Bad double!" << std::endl;
            }
            
        }
    }
    else
    {
        std::cout << "File in not open" << std::endl;
    }

    return 0;
    auto v = tokenise(csvLine, ',');
    for (auto val : v)
        std::cout << val << " " << std::endl;
}