#include <vector>
#include <iostream>
#include <exception>
#include <string>

#include "FileHelper.hpp"

int main()
{
    std::locale::global(std::locale("en_US.UTF-8"));
    std::ios::sync_with_stdio(false);
    try {
        FileHelper::writeAppend("test.txt", "123");
        std::vector<unsigned char> data{ 'A', 'B', '\r', '\n', 0xE6, 0xB8, 0xAC };
        FileHelper::writeAppend(L"test.txt", data);

        FileHelper::writeAppend("test.txt", L"試");

        std::string str = FileHelper::readAll("test.txt");
        std::cout << "str: " << str << std::endl;

        std::wstring wstr = FileHelper::readAll<std::wstring>("test.txt");
        std::wcout << "wstr: " << wstr << std::endl;

        FileHelper::overwrite("test.txt", "hello world !");

        auto vector = FileHelper::readAll<std::vector<char>>(L"test.txt");
        std::cout << "vector: " << std::string(vector.cbegin(), vector.cend()) << std::endl;
        
        FileHelper::overwrite(L"test.txt", L"你好 !");
        wstr = FileHelper::readAll<std::wstring>(L"test.txt");
        std::wcout << "wstr: " << wstr << std::endl;
        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cin.ignore();
    return 0;
}