#include <iostream>
#include <string>
#include <fstream>


void WorkFile(std::string filename1, std::string filename2)
{
    std::string str1, str2;
    std::fstream file1(filename1, std::fstream::in);
    std::fstream file2(filename2, std::fstream::in);
    if (!file1.is_open() || !file2.is_open())
    {
        std::cout << "Wrong?? " << std::endl;
        return;
    }
    int num = 0, i = 0;
    while (!file1.eof())
    {
        i = 0;
        std::getline(file1, str1);
        while (!file2.eof())
        {
            std::getline(file2, str2);
            if (str1 == str2)
            {
                i = 1;
                break;
            }
        }
        if (i == 0)
        {
            std::cout << num << "." << str1 << std::endl;
        }
        num++;
        file2.close();
        file2.open(filename2);
    }
    file2.close();
}
int main()
{
    std::string line1, line2, filename1, filename2;
    std::cout << "Name of first file:  ";
    std::cin >> filename1;
    std::cout << "Name of second file:  ";
    std::cin >> filename2;
    std::cout << std::endl << "File #1:" << std::endl;
    WorkFile(filename1, filename2);
    std::cout << std::endl << "File #2:" << std::endl;
    WorkFile(filename2, filename1);
    return 0;
}