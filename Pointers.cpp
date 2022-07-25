#include <iostream>


int a = 0;
int b = 0;
int* ptrA = nullptr;
int* ptrB = nullptr;

int main()
{
    std::cout << "Please input an integer: " << std::endl << std::endl;
    std::cout << "> ";

    std::cin >> a;
    std::cin.clear();
    std::cout << std::endl;

    std::cout << "Please input another integer: " << std::endl << std::endl;
    std::cout << "> ";

    std::cin >> b;
    std::cin.clear();
    std::cout << std::endl;

    ptrA = &a;
    ptrB = &b;

    std::cout << "ptrA points to value " << *ptrA << " at address " << ptrA << "\nptrB points to value " << *ptrB << " at address " << ptrB << std::endl;
    std::cin >> a;
    std::cin.clear();

    return 0;
}