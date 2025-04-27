#include <iostream>
#include <fstream>
#include <string>

void SearchAndReplace(std::string& line, std::string toReplace, std::string newString)
{
    size_t pos = line.find(toReplace);
    while (pos != std::string::npos)
    {
        line.erase(pos, toReplace.length());
        line.insert(pos, newString);
        pos = line.find(toReplace);
    }
}

int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string fileName (av[1]);
    std::string newFile (fileName + ".replace");
    std::string toReplace (av[2]);
    std::string newString (av[3]);
    std::string line;

    std::ifstream inputFile(av[1]);
    if (!inputFile)
    {
        std::cerr << "Error : can't open file!" << std::endl; 
        return 1;
    }
    else if (inputFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error : Empty file!" << std::endl;
        inputFile.close();
        return 1;
        
    }
    std::ofstream outputFile(newFile.c_str());

    if (inputFile.is_open() && outputFile.is_open())
    {
        while (std::getline(inputFile, line))
        {
            SearchAndReplace(line, toReplace, newString);
            outputFile << line;
            if (!inputFile.eof())
                outputFile << std::endl;
        }
    }
    else 
        std::cerr << "Error : can't open file!" << std::endl;
    inputFile.close();
    outputFile.close();
}